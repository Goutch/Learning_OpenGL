//
// Created by User on 18-Mar.-2020.
//

#include "ChunkLoader.h"
#include "ChunkRenderer.h"
#include "ChunkManager.h"
#include <queue>

struct comp {
    bool operator()(const std::pair<float, ChunkPosition> &a, const std::pair<float, ChunkPosition> &b) {
        return a.first >b.first;
    }
};

void ChunkLoader::setLoaderTransform(Transform &transform) {
    this->loader = &transform;
}

ChunkLoader::ChunkLoader(Scene &scene, ChunkManager &manager, EntityMaterial &solid_material,
                         EntityMaterial &transparent_material) {
    this->manager = &manager;
    this->scene = &scene;
    this->chunk_transparent_material = &transparent_material;
    this->chunk_solid_material = &solid_material;

    std::priority_queue<std::pair<float, ChunkPosition>, std::vector<std::pair<float, ChunkPosition>>, comp> view_positions;
    for (int x = -range; x <= range; ++x) {
        for (int y = -range; y < range; ++y) {
            for (int z = -range; z <= range; ++z) {
                float dist = sqrt((x * x) + (y * y) + (z * z));
                if (dist < range) {
                    view_positions.emplace(dist, ChunkPosition(x, y, z));
                }
            }
        }
    }
    while (!view_positions.empty()) {
        view.push_back(view_positions.top().second);
        view_positions.pop();
    }
}

void ChunkLoader::update(float delta) {
    Timer t;
   Log::debug("UPDATE_BEGIN:");

    std::list<ChunkPosition> finished_loading_chunks;
    for (auto &c:loading_chunks) {
        const Thread<void> &t = c.second.second;
        if (t.isFinish()) {
            ChunkRenderer *chunk = c.second.first;
            chunk->onBuildFinish();
            chunk->setEnabled(true);
            loaded_chunks.emplace(c.first, chunk);
            finished_loading_chunks.emplace_back(c.first);
        }
    }
    for (const auto &c:finished_loading_chunks) {
        loading_chunks.erase(c);
    }

    //Log::debug("build finish time:"+std::to_string(t.ms()));
    //t.reset();
    ChunkPosition loader_chunk_position = manager->worldToChunk(loader->position());
    int range = 16;
    //add to chunk_pool if it is too far away
    std::list<ChunkPosition> unloaded_chunk;
    for (auto &c:loaded_chunks) {
        ChunkPosition distance = c.second->getChunk().position - loader_chunk_position;
        if (abs(distance.x) > range ||
            abs(distance.y) > range ||
            abs(distance.z) > range) {
            chunks_pool.push_back(c.second);
            unloaded_chunk.push_back(c.second->getChunk().position);
            c.second->setEnabled(false);
        }
    }
    //remove from loaded chunks too far away
    for (auto &pos:unloaded_chunk) {
        loaded_chunks.erase(pos);
    }


    //Log::debug("unload time:"+std::to_string(t.ms()));
    // t.reset();
    //load all chunks in range create and new renderer if the pool is empty
    for (auto chunk_offset:view) {
        ChunkPosition chunk_pos = ChunkPosition(loader_chunk_position.x + chunk_offset.x,
                                                loader_chunk_position.y + chunk_offset.y,
                                                loader_chunk_position.z + chunk_offset.z);
        auto it = loaded_chunks.find(chunk_pos);
        //if is not currently loaded or loading
        if (it == loaded_chunks.end() && loading_chunks.find(chunk_pos) == loading_chunks.end()) {
            //if no chunk renderer is avalable in the pool create new one
            if (loading_chunks.size() == MAX_LOADER_THREADS) {
                break;
            }
            if (chunks_pool.empty()) {
                auto c = new ChunkRenderer(*chunk_solid_material, *chunk_transparent_material, *manager);
                scene->instantiate(c);
                chunks_pool.push_back(c);
            }
            loading_chunks.emplace(std::make_pair(chunk_pos,
                                                  std::make_pair(chunks_pool.front(), Thread<void>(
                                                          std::make_shared<std::future<void>>(
                                                                  std::async(std::launch::async,
                                                                             &ChunkRenderer::setChunk,
                                                                             chunks_pool.front(),
                                                                             chunk_pos))))));

            chunks_pool.pop_front();
        }
    }
    Log::debug("UPDATE_END:"+std::to_string(t.ms()));
}


ChunkLoader::~ChunkLoader() {

}

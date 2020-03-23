//
// Created by User on 18-Mar.-2020.
//

#include "ChunkLoader.h"
#include "ChunkRenderer.h"
#include "ChunkManager.h"

void ChunkLoader::setLoaderTransform(Transform &transform) {
    this->loader = &transform;
}

ChunkLoader::ChunkLoader(Scene &scene, ChunkManager &manager,CameraFrustum &cameraFrustum) {
    this->manager = &manager;
    this->scene = &scene;
    this->camera_frustum=&cameraFrustum;
    chunk_transparent_material.setTransparent(true);
}

void ChunkLoader::update(float delta) {
    vec3 p = loader->position();
    p *= vec3(1 / (float) Chunk::SIZE_X, 1 / (float) Chunk::SIZE_Y, 1 / (float) Chunk::SIZE_Z);
    p.x = floor(p.x);
    p.y = floor(p.y);
    p.z = floor(p.z);
    ChunkPosition loader_position = ChunkPosition(p.x, p.y, p.z);

    int range = 9;
    //add to pool chunks if it is too far away
    for (auto &c:loaded_chunks) {
        ChunkPosition distance = c.second->getChunk().position - loader_position;
        if (abs(distance.x) > range ||
            abs(distance.y) > range ||
            abs(distance.z) > range) {
            chunk_pool.push_back(c.second);
        }
    }
    //remove from loaded chunks too far away
    for (auto &c:chunk_pool) {
        loaded_chunks.erase(c->getChunk().position);
    }
    //load all chunks in range create and new renderer if the pool is empty
    for (int x = -range; x <= range; ++x) {
        for (int y = -1; y < 1; ++y) {
            for (int z = -range; z <= range; ++z) {
                ChunkPosition chunk_pos = ChunkPosition(x + loader_position.x, y + loader_position.y,
                                                        z + loader_position.z);
                //is not currently loaded
                auto it = loaded_chunks.find(chunk_pos);
                Timer t;
                if (it == loaded_chunks.end()) {
                    if (!chunk_pool.empty()) {

                        chunk_pool.front()->setChunk(&manager->getChunk(chunk_pos.x, chunk_pos.y, chunk_pos.z));

                        loaded_chunks.emplace(chunk_pos, chunk_pool.front());
                        chunk_pool.pop_front();
                    } else {
                        createChunk(chunk_pos.x, chunk_pos.y, chunk_pos.z);
                    }
                    break;
                }

            }
        }
    }
}


void ChunkLoader::createChunk(int x, int y, int z) {
    auto c = new ChunkRenderer(chunk_solid_material, chunk_transparent_material, *manager,*camera_frustum);
    scene->instantiate(c);
    c->setChunk(&manager->getChunk(x, y, z));
    loaded_chunks.emplace(c->getChunk().position, c);
}

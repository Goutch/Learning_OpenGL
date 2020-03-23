//
// Created by User on 13-Mar.-2020.
//

#include "ChunkRenderer.h"

#include "VoxelDictionary.h"
#include "ChunkManager.h"
#include <thread>
#include <future>

ChunkRenderer::ChunkRenderer(const EntityMaterial &solid_material, const EntityMaterial &transparent_material,
                             ChunkManager &chunkManager) :
        Entity(vec3(0), vec3(0), vec3(1)) {
    this->solid_material = &solid_material;
    this->transparent_material = &transparent_material;
    this->chunkManager = &chunkManager;

    setEnabled(false);
}

void ChunkRenderer::draw(const Scene &scene) const {
    if(!current_chunk->empty &&
    thread_results.empty()&&
    scene.getCamera().isBoxInFrustum(transform.position(),vec3(Chunk::SIZE_X,Chunk::SIZE_Y,Chunk::SIZE_Z)))
    {
        Renderer &renderer = scene.getRenderer();
        renderer.draw(solid_voxels, *solid_material, transform);
        renderer.draw(transparent_voxels, *transparent_material, transform);
    }
}

float ChunkRenderer::getDistanceToCamera() const {
    return glm::distance(getChunkCenter(),
                         (*pCamera)->transform.position());
}
vec3 ChunkRenderer::getChunkCenter() const{
    return this->transform.position() + vec3(Chunk::SIZE_Z / 2, Chunk::SIZE_Y / 2, Chunk::SIZE_Z / 2);
}
void ChunkRenderer::init(Scene &scene) {
    Entity::init(scene);
    pCamera = &scene.getCameraPtr();
}

void ChunkRenderer::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
    if (!thread_results.empty()) {

        auto status = thread_results.front().wait_for(std::chrono::milliseconds(0));
        if (status == std::future_status::ready) {
            thread_results.pop();
            onBuildFinish();
        }
    }


}

void ChunkRenderer::setChunk(Chunk *chunk) {

    current_chunk = chunk;
    int chunk_x = chunk->position.x;
    int chunk_y = chunk->position.y;
    int chunk_z = chunk->position.z;
    chunk_up = &chunkManager->getChunk(chunk_x, chunk_y + 1, chunk_z);
    chunk_down = &chunkManager->getChunk(chunk_x, chunk_y - 1, chunk_z);
    chunk_left = &chunkManager->getChunk(chunk_x - 1, chunk_y, chunk_z);
    chunk_right = &chunkManager->getChunk(chunk_x + 1, chunk_y, chunk_z);
    chunk_front = &chunkManager->getChunk(chunk_x, chunk_y, chunk_z + 1);
    chunk_back = &chunkManager->getChunk(chunk_x, chunk_y, chunk_z - 1);
    this->transform.position(vec3(
            chunk->position.x * Chunk::SIZE_X,
            chunk->position.y * Chunk::SIZE_Y,
            chunk->position.z * Chunk::SIZE_Z));

    thread_results.push(std::async(std::launch::async, &ChunkRenderer::rebuild, this));
}

Chunk &ChunkRenderer::getChunk() const {
    return *current_chunk;
}

void ChunkRenderer::rebuild() {

    std::lock_guard<std::mutex> lock(mesh_mutex);
    indicies.clear();
    vertex_positions.clear();
    vertex_colors.clear();
    for (int x = 0; x < Chunk::SIZE_X; ++x) {
        for (int z = 0; z < Chunk::SIZE_Z; ++z) {
            for (int y = 0; y < Chunk::SIZE_Y; ++y) {
                const Voxel &voxel = VOXELS_DICTIONNARY[current_chunk->at(x, y, z)];
                if (voxel.id != VOXELS::AIR) {
                    createVoxel(x, y, z, voxel);
                }
            }
        }
    }
}

void ChunkRenderer::onBuildFinish() {
    if(!indicies.empty())
    {
        solid_voxels.indicies(indicies.data(), indicies.size());
        solid_voxels.vertices(&vertex_positions[0].x, vertex_positions.size() * 3);
        solid_voxels.colors(&vertex_colors[0].r, vertex_colors.size() * 4);
    } else{
        current_chunk->empty=true;
    }

    indicies.clear();
    vertex_positions.clear();
    vertex_colors.clear();
}

void ChunkRenderer::createVoxel(int x, int y, int z, const Voxel &voxel) {
    //up
    createSide(x, y, z, voxel, Side::up);
    createSide(x, y, z, voxel, Side::down);
    createSide(x, y, z, voxel, Side::right);
    createSide(x, y, z, voxel, Side::left);
    createSide(x, y, z, voxel, Side::front);
    createSide(x, y, z, voxel, Side::back);
}

void ChunkRenderer::createSide(int x, int y, int z, const Voxel &voxel, ChunkRenderer::Side side) {
    unsigned int indices_offset = vertex_positions.size();
    bool added_side = false;
    bool inverse = false;
    switch (side) {
        case up: {
            const Voxel &voxel_up = VOXELS_DICTIONNARY.at(
                    y >= Chunk::SIZE_Y - 1 ? chunk_up->at(x, 0, z) : current_chunk->at(x, y + 1, z));
            if (voxel_up.is_transparent && voxel_up != voxel) {
                vertex_positions.emplace_back(x, y + 1, z);
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                added_side = true;
            }
            break;
        }
        case down: {
            const Voxel &voxel_down = VOXELS_DICTIONNARY.at(
                    y <= 0 ? chunk_down->at(x, Chunk::SIZE_Y - 1, z) : current_chunk->at(x, y - 1, z));
            if (voxel_down.is_transparent && voxel_down != voxel) {
                vertex_positions.emplace_back(x, y, z);
                vertex_positions.emplace_back(vec3(x + 1, y, z));
                vertex_positions.emplace_back(vec3(x, y, z + 1));
                vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                inverse = true;
                added_side = true;
            }
            break;
        }
        case right: {
            const Voxel &voxel_right = VOXELS_DICTIONNARY.at(
                    x >= Chunk::SIZE_X - 1 ? chunk_right->at(0, y, z) : current_chunk->at(x + 1, y, z));
            if (voxel_right.is_transparent && voxel_right != voxel) {
                vertex_positions.emplace_back(x + 1, y, z);
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                added_side = true;
                inverse = true;
            }
            break;
        }
        case left: {
            const Voxel &voxel_left = VOXELS_DICTIONNARY.at(
                    x <= 0 ? chunk_left->at(Chunk::SIZE_X - 1, y, z) : current_chunk->at(x - 1, y, z));
            if (voxel_left.is_transparent && voxel_left != voxel) {
                vertex_positions.emplace_back(x, y, z);
                vertex_positions.emplace_back(vec3(x, y + 1, z));
                vertex_positions.emplace_back(vec3(x, y, z + 1));
                vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                added_side = true;
            }
            break;
        }
        case front: {
            const Voxel &voxel_front = VOXELS_DICTIONNARY.at(
                    z >= Chunk::SIZE_Z - 1 ? chunk_front->at(x, y, 0) : current_chunk->at(x, y, z + 1));
            if (voxel_front.is_transparent && voxel_front != voxel) {
                vertex_positions.emplace_back(x, y, z + 1);
                vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                added_side = true;
                inverse = true;
            }
            break;
        }
        case back: {
            const Voxel &voxel_back = VOXELS_DICTIONNARY.at(
                    z <= 0 ? chunk_back->at(x, y, Chunk::SIZE_Z - 1) : current_chunk->at(x, y, z - 1));
            if (voxel_back.is_transparent && voxel_back != voxel) {
                vertex_positions.emplace_back(x, y, z);
                vertex_positions.emplace_back(vec3(x + 1, y, z));
                vertex_positions.emplace_back(vec3(x, y + 1, z));
                vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                added_side = true;
            }
            break;
        }
    }
    if (added_side) {
        vertex_colors.emplace_back(voxel.color);
        vertex_colors.emplace_back(voxel.color);
        vertex_colors.emplace_back(voxel.color);
        vertex_colors.emplace_back(voxel.color);
        if (inverse) {
            indicies.push_back(0 + indices_offset);
            indicies.push_back(1 + indices_offset);
            indicies.push_back(3 + indices_offset);
            indicies.push_back(3 + indices_offset);
            indicies.push_back(2 + indices_offset);
            indicies.push_back(0 + indices_offset);
        } else {
            indicies.push_back(3 + indices_offset);
            indicies.push_back(1 + indices_offset);
            indicies.push_back(0 + indices_offset);
            indicies.push_back(0 + indices_offset);
            indicies.push_back(2 + indices_offset);
            indicies.push_back(3 + indices_offset);
        }
    }
}


std::size_t ChunkRenderer::operator<(const ChunkRenderer &other) const {
    return getDistanceToCamera() < other.getDistanceToCamera();
}








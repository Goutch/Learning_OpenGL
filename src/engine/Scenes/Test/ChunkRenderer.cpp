//
// Created by User on 13-Mar.-2020.
//

#include "ChunkRenderer.h"

#include "VoxelDictionary.h"
#include "ChunkManager.h"
#include <future>

ChunkRenderer::ChunkRenderer(const EntityMaterial &solid_material, const EntityMaterial &transparent_material,
                             ChunkManager &chunkManager) :
        Entity(vec3(0), vec3(0), vec3(1)) {
    this->material = &solid_material;
    this->transparent_material = &transparent_material;
    this->chunkManager = &chunkManager;
    setEnabled(false);
}

void ChunkRenderer::draw(const Scene &scene) const {
    if ((!empty || !transparent_empty) &&
        threads.empty() &&
        scene.getCamera().isSphereInFrustum(getChunkCenter(), Chunk::RADIUS)) {
        Renderer &renderer = scene.getRenderer();
        if (!empty)renderer.draw(mesh, *material, transform);
        if (!transparent_empty)renderer.draw(transparent_mesh, *transparent_material, transform);
    }
}

float ChunkRenderer::getDistanceToCamera() const {
    return glm::distance(getChunkCenter(),
                         (*pCamera)->transform.position());
}

vec3 ChunkRenderer::getChunkCenter() const {
    return this->transform.position() + vec3(Chunk::SIZE_Z * 0.5f, Chunk::SIZE_Y * 0.5f, Chunk::SIZE_Z * 0.5f);
}

void ChunkRenderer::init(Scene &scene) {
    Entity::init(scene);
    pCamera = &scene.getCameraPtr();
}

void ChunkRenderer::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
    if (!threads.empty()) {
        if (threads.front().isFinish()) {
            threads.pop();
            onBuildFinish();
        }
    }
}
bool ChunkRenderer::isLoading() {
    return !threads.empty();
}

void ChunkRenderer::setChunk(ChunkPosition position) {
    mesh_mutex.lock();
    current_chunk = &chunkManager->getChunk(position.x,position.y,position.z);
    chunk_up = &chunkManager->getChunk(position.x, position.y + 1, position.z);
    chunk_down = &chunkManager->getChunk(position.x, position.y - 1,position.z);
    chunk_left = &chunkManager->getChunk(position.x - 1,position.y, position.z);
    chunk_right = &chunkManager->getChunk(position.x + 1, position.y, position.z);
    chunk_front = &chunkManager->getChunk(position.x, position.y, position.z + 1);
    chunk_back = &chunkManager->getChunk(position.x, position.y, position.z - 1);
    rebuild();
}
void ChunkRenderer::setChunkAsynch(ChunkPosition position) {
    this->transform.position(vec3(
            position.x * Chunk::SIZE_X,
            position.y * Chunk::SIZE_Y,
            position.z * Chunk::SIZE_Z));
    threads.push(Thread<void>(
            std::make_shared<std::future<void>>(std::async(std::launch::async, &ChunkRenderer::setChunk, this,position))));
}

Chunk &ChunkRenderer::getChunk() const {
    return *current_chunk;
}

void ChunkRenderer::rebuild() {
    indicies.clear();
    vertex_occlusion.clear();
    vertex_positions.clear();
    vertex_colors.clear();
    vertex_uv.clear();

    transparent_indicies.clear();
    transparent_vertex_colors.clear();
    transparent_vertex_positions.clear();
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
    mesh_mutex.unlock();
}

void ChunkRenderer::onBuildFinish() {
    if (!indicies.empty()) {
        mesh.indicies(indicies.data(), indicies.size());
        mesh.vertices(&vertex_positions[0].x, vertex_positions.size() * 3);
        mesh.colors(&vertex_colors[0].r, vertex_colors.size() * 4);
        mesh.uvs(&vertex_uv[0].x, vertex_uv.size() * 2);
        mesh.put(4, 4, &vertex_occlusion[0].x, vertex_occlusion.size() * 4);
        empty = false;
    } else {
        empty = true;
    }
    indicies.clear();
    vertex_occlusion.clear();
    vertex_positions.clear();
    vertex_colors.clear();
    vertex_uv.clear();
    if (!transparent_indicies.empty()) {
        transparent_mesh.indicies(transparent_indicies.data(), transparent_indicies.size());
        transparent_mesh.vertices(&transparent_vertex_positions[0].x, transparent_vertex_positions.size() * 3);
        transparent_mesh.colors(&transparent_vertex_colors[0].r, transparent_vertex_colors.size() * 4);
        transparent_empty = false;
    } else {
        transparent_empty = true;
    }
    transparent_indicies.clear();
    transparent_vertex_colors.clear();
    transparent_vertex_positions.clear();
}

void ChunkRenderer::createVoxel(int x, int y, int z, const Voxel &voxel) {
    createSide(x, y, z, voxel, Side::up);
    createSide(x, y, z, voxel, Side::down);
    createSide(x, y, z, voxel, Side::right);
    createSide(x, y, z, voxel, Side::left);
    createSide(x, y, z, voxel, Side::front);
    createSide(x, y, z, voxel, Side::back);
}

void ChunkRenderer::createSide(int x, int y, int z, const Voxel &voxel, ChunkRenderer::Side side) {
    unsigned int indices_offset = vertex_positions.size();
    unsigned int transparent_indices_offset=transparent_vertex_positions.size();
    bool added_side = false;
    bool inverse = false;
    switch (side) {
        case up: {
            const Voxel &voxel_up = VOXELS_DICTIONNARY.at(
                    y >= Chunk::SIZE_Y - 1 ? chunk_up->at(x, 0, z) : current_chunk->at(x, y + 1, z));
            if (voxel_up.is_transparent && voxel_up != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x, y + 1, z);
                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                    vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x + i + (current_chunk->position.x * Chunk::SIZE_X),
                                    y + 1 + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z + j + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                } else {
                    transparent_vertex_positions.emplace_back(x, y + 1, z);
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                    transparent_vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                }
                added_side = true;

            }
            break;
        }
        case down: {
            const Voxel &voxel_down = VOXELS_DICTIONNARY.at(
                    y <= 0 ? chunk_down->at(x, Chunk::SIZE_Y - 1, z) : current_chunk->at(x, y - 1, z));
            if (voxel_down.is_transparent && voxel_down != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x, y, z);
                    vertex_positions.emplace_back(vec3(x + 1, y, z));
                    vertex_positions.emplace_back(vec3(x, y, z + 1));
                    vertex_positions.emplace_back(vec3(x + 1, y, z + 1));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x + i + (current_chunk->position.x * Chunk::SIZE_X),
                                    y - 1 + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z + j + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                }
                else{
                    transparent_vertex_positions.emplace_back(x, y, z);
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y, z));
                    transparent_vertex_positions.emplace_back(vec3(x, y, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                }
                inverse = true;
                added_side = true;
            }

            break;
        }
        case right: {
            const Voxel &voxel_right = VOXELS_DICTIONNARY.at(
                    x >= Chunk::SIZE_X - 1 ? chunk_right->at(0, y, z) : current_chunk->at(x + 1, y, z));
            if (voxel_right.is_transparent && voxel_right != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x + 1, y, z);

                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                    vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x + 1 + (current_chunk->position.x * Chunk::SIZE_X),
                                    y + i + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z + j + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);

                } else {
                    transparent_vertex_positions.emplace_back(x + 1, y, z);
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                }
                added_side = true;
                inverse = true;
            }
            break;
        }
        case left: {
            const Voxel &voxel_left = VOXELS_DICTIONNARY.at(
                    x <= 0 ? chunk_left->at(Chunk::SIZE_X - 1, y, z) : current_chunk->at(x - 1, y, z));
            if (voxel_left.is_transparent && voxel_left != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x, y, z);
                    vertex_positions.emplace_back(vec3(x, y + 1, z));
                    vertex_positions.emplace_back(vec3(x, y, z + 1));
                    vertex_positions.emplace_back(vec3(x, y + 1, z + 1));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x - 1 + (current_chunk->position.x * Chunk::SIZE_X),
                                    y + i + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z + j + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);

                } else {
                    transparent_vertex_positions.emplace_back(x, y, z);
                    transparent_vertex_positions.emplace_back(vec3(x, y + 1, z));
                    transparent_vertex_positions.emplace_back(vec3(x, y, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                }
                added_side = true;
            }
            break;
        }
        case front: {
            const Voxel &voxel_front = VOXELS_DICTIONNARY.at(
                    z >= Chunk::SIZE_Z - 1 ? chunk_front->at(x, y, 0) : current_chunk->at(x, y, z + 1));
            if (voxel_front.is_transparent && voxel_front != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x, y, z + 1);
                    vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                    vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x + i + (current_chunk->position.x * Chunk::SIZE_X),
                                    y + j + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z + 1 + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);

                } else {
                    transparent_vertex_positions.emplace_back(x, y, z + 1);
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x, y + 1, z + 1));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z + 1));
                }
                added_side = true;
                inverse = true;
            }
            break;
        }
        case back: {
            const Voxel &voxel_back = VOXELS_DICTIONNARY.at(
                    z <= 0 ? chunk_back->at(x, y, Chunk::SIZE_Z - 1) : current_chunk->at(x, y, z - 1));
            if (voxel_back.is_transparent && voxel_back != voxel) {
                if (!voxel.is_transparent) {
                    vertex_positions.emplace_back(x, y, z);
                    vertex_positions.emplace_back(vec3(x + 1, y, z));
                    vertex_positions.emplace_back(vec3(x, y + 1, z));
                    vertex_positions.emplace_back(vec3(x + 1, y + 1, z));


                    bool neighbours[3][3];
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            neighbours[i + 1][j + 1] = !VOXELS_DICTIONNARY[chunkManager->getVoxel(
                                    x + i + (current_chunk->position.x * Chunk::SIZE_X),
                                    y + j + (current_chunk->position.y * Chunk::SIZE_Y),
                                    z - 1 + (current_chunk->position.z * Chunk::SIZE_Z))].is_transparent;
                        }
                    }
                    vec4 occlusion = vec4(neighbours[0][0] + neighbours[1][0] + neighbours[0][1],
                                          neighbours[0][1] + neighbours[0][2] + neighbours[1][2],
                                          neighbours[2][1] + neighbours[2][0] + neighbours[1][0],
                                          neighbours[1][2] + neighbours[2][2] + neighbours[2][1]);

                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);
                    vertex_occlusion.emplace_back(occlusion);

                } else {
                    transparent_vertex_positions.emplace_back(x, y, z);
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y, z));
                    transparent_vertex_positions.emplace_back(vec3(x, y + 1, z));
                    transparent_vertex_positions.emplace_back(vec3(x + 1, y + 1, z));
                }
                added_side = true;
            }
            break;
        }
    }

    if (added_side) {
        if (!voxel.is_transparent) {
            vertex_colors.emplace_back(voxel.color);
            vertex_colors.emplace_back(voxel.color);
            vertex_colors.emplace_back(voxel.color);
            vertex_colors.emplace_back(voxel.color);

            vertex_uv.emplace_back(vec2(0, 0));
            vertex_uv.emplace_back(vec2(1, 0));
            vertex_uv.emplace_back(vec2(0, 1));
            vertex_uv.emplace_back(vec2(1, 1));

            //  1---3
            //  | / |
            //  0---2
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
        } else {
            transparent_vertex_colors.emplace_back(voxel.color);
            transparent_vertex_colors.emplace_back(voxel.color);
            transparent_vertex_colors.emplace_back(voxel.color);
            transparent_vertex_colors.emplace_back(voxel.color);


            //  1---3
            //  | / |
            //  0---2
            if (inverse) {

                transparent_indicies.push_back(0 + transparent_indices_offset);
                transparent_indicies.push_back(1 + transparent_indices_offset);
                transparent_indicies.push_back(3 + transparent_indices_offset);
                transparent_indicies.push_back(3 + transparent_indices_offset);
                transparent_indicies.push_back(2 + transparent_indices_offset);
                transparent_indicies.push_back(0 + transparent_indices_offset);
            } else {
                transparent_indicies.push_back(3 + transparent_indices_offset);
                transparent_indicies.push_back(1 + transparent_indices_offset);
                transparent_indicies.push_back(0 + transparent_indices_offset);
                transparent_indicies.push_back(0 + transparent_indices_offset);
                transparent_indicies.push_back(2 + transparent_indices_offset);
                transparent_indicies.push_back(3 + transparent_indices_offset);
            }
        }
    }
}


std::size_t ChunkRenderer::operator<(const ChunkRenderer &other) const {
    return getDistanceToCamera() < other.getDistanceToCamera();
}











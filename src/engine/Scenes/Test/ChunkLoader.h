#pragma once
#include <API_ALL.h>
class ChunkRenderer;
class ChunkManager;

#include <thread>
#include "Chunk.h"
class ChunkLoader {
    Shader chunk_shader=Shader("../src/engine/Scenes/Test/Shader/VoxelVertex.glsl","../src/engine/Scenes/Test/Shader/VoxelFragment.glsl");
    EntityMaterial chunk_transparent_material=EntityMaterial(chunk_shader,Color::WHITE);
    EntityMaterial chunk_solid_material=EntityMaterial(chunk_shader,Color::WHITE);
    Transform* loader;
    std::unordered_map<ChunkPosition,ChunkRenderer*,ChunkPosition::hash_fun> loaded_chunks;
    std::list<ChunkRenderer*> chunk_pool;
    ChunkManager* manager;
    Scene* scene;

public:
    ChunkLoader(Scene& scene ,ChunkManager& manager);
    void setLoaderTransform(Transform& transform);
    void update(float delta);
    void createChunk(int x,int y,int z);
};




#pragma once
#include <API_ALL.h>
class ChunkRenderer;
class ChunkManager;

#include <thread>
#include "Chunk.h"
class ChunkLoader {
    EntityMaterial* chunk_transparent_material;
    EntityMaterial* chunk_solid_material;
    Transform* loader;
    std::unordered_map<ChunkPosition,ChunkRenderer*,ChunkPosition::hash_fun> loaded_chunks;
    std::list<ChunkRenderer*> chunk_pool;
    ChunkManager* manager;
    Scene* scene;

public:
    ChunkLoader(Scene& scene ,ChunkManager& manager,EntityMaterial& solid_material,
    EntityMaterial& transparent_material);
    void setLoaderTransform(Transform& transform);
    void update(float delta);
    void createChunk(int x,int y,int z);
};




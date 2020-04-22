#pragma once
#include <API_ALL.h>
class ChunkRenderer;
class ChunkManager;

#include <thread>
#include "Chunk.h"
#include <Utils/Thread.h>
class ChunkLoader {
    const int MAX_LOADER_THREADS=1;
    EntityMaterial* chunk_transparent_material;
    EntityMaterial* chunk_solid_material;
    Transform* loader;
    std::unordered_map<ChunkPosition,ChunkRenderer*,ChunkPosition::hash_fun> loaded_chunks;
    std::unordered_map<ChunkPosition,std::pair<ChunkRenderer*,Thread<void>>,ChunkPosition::hash_fun> loading_chunks;//renderers currently loading
    std::list<ChunkRenderer*> chunks_pool;//unused chunks renderer
    int range=16;
    std::list<ChunkPosition> view;
    ChunkManager* manager;
    Scene* scene;

public:
    ChunkLoader(Scene& scene ,ChunkManager& manager,EntityMaterial& solid_material,
    EntityMaterial& transparent_material);
    void setLoaderTransform(Transform& transform);
    void update(float delta);
    ~ChunkLoader();
};




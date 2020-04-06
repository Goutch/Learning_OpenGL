#pragma once

#include "Chunk.h"
#include "unordered_map"
#include <cmath>
#include <mutex>

class ChunkManager {
    std::unordered_map<ChunkPosition, Chunk *, ChunkPosition::hash_fun> chunk_map;
    mutable std::mutex chunk_map_mutex;
public:
    ~ChunkManager();
    bool exist(int x, int y, int z) const;
    Chunk &getChunk(int x, int y, int z);

    unsigned char getVoxel(int x, int y, int z);
};

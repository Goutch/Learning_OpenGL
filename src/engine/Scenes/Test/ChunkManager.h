#pragma once

#include "Chunk.h"
#include "unordered_map"
#include <cmath>

class ChunkManager {
    std::unordered_map<ChunkPosition, Chunk *, ChunkPosition::hash_fun> chunk_map;
public:
    ~ChunkManager();
    bool exist(int x, int y, int z) const;
    Chunk &getChunk(int x, int y, int z);

    unsigned char getVoxel(int x, int y, int z);
};

//
// Created by User on 13-Mar.-2020.
//

#include "ChunkManager.h"
#include "ChunkGenerator.h"
Chunk &ChunkManager::getChunk(int x, int y, int z) {
    if(!exist(x,y,z))
    {
        auto c=new Chunk(x,y,z);
        chunk_map.emplace(c->position,c);
        ChunkGenerator::generate(*c);
        return *c;
    }
    return *chunk_map.at({x,y,z});
}

ChunkManager::~ChunkManager() {
    for (auto c:chunk_map) {
        delete c.second;
    }
}

bool ChunkManager::exist(int x,int y, int z) const {
    return chunk_map.find({x,y,z})!= chunk_map.end();
}

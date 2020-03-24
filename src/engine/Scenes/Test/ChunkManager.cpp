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

#include "Core/Log.h"
unsigned char ChunkManager::getVoxel(int x,int y,int z){
    ChunkPosition chunk_pos=ChunkPosition(floor(x/(float)Chunk::SIZE_X),floor(y/(float)Chunk::SIZE_Y),floor(z/(float)Chunk::SIZE_Z));
    vec3 voxel_position=vec3(x-(chunk_pos.x*Chunk::SIZE_X),y-(chunk_pos.y*Chunk::SIZE_Y),z-(chunk_pos.z*Chunk::SIZE_Z));
    return getChunk(chunk_pos.x,chunk_pos.y,chunk_pos.z).at(voxel_position.x,voxel_position.y,voxel_position.z);
}
bool ChunkManager::exist(int x,int y, int z) const {
    return chunk_map.find({x,y,z})!= chunk_map.end();
}

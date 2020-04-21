//
// Created by User on 13-Mar.-2020.
//

#include "ChunkGenerator.h"
#include "Voxel.h"
#include "Chunk.h"
#include "VoxelDictionary.h"
#include <Utils/SimplexNoise.h>

void ChunkGenerator::generate(Chunk &chunk) {
    Timer t;
    vec3 chunk_pos = vec3((chunk.position.x * Chunk::SIZE_X),
                          (chunk.position.y * Chunk::SIZE_Y),
                          (chunk.position.z * Chunk::SIZE_Z));
    vec3 voxel_pos = chunk_pos;
    float scale_layer_1 = 0.005;
    float scale_layer_3 = 0.005;
    float scale_layer_2 = 0.01;


    //float scale_caves=0.05;
    int index=0;
    for (int x = 0; x < Chunk::SIZE_X; ++x) {
        voxel_pos.x+=1;
        for (int z = 0; z < Chunk::SIZE_Z; ++z) {
            voxel_pos.z+=1;
            float layer_1=SimplexNoise::noise(voxel_pos.x * scale_layer_1, voxel_pos.z * scale_layer_1) *32;
            float layer_2=SimplexNoise::noise((voxel_pos.x-512)* scale_layer_2, (voxel_pos.z-512)* scale_layer_2) *layer_1;
            float layer_3=(SimplexNoise::noise((voxel_pos.x+512)* scale_layer_3, (voxel_pos.z+512)* scale_layer_3)+0.5f) *layer_2;

            float h= layer_1+layer_2+layer_3;
            for (int y = 0; y < Chunk::SIZE_Y; ++y) {
                voxel_pos.y+=1;
                /*float cave=SimplexNoise::noise(voxel_pos.x*scale_caves,voxel_pos.y*scale_caves,voxel_pos.z*scale_caves);
                if(cave<-0.4&&voxel_pos.y<h)
                {
                    chunk.set(index, VOXELS::AIR);
                }
               else */if (voxel_pos.y < h &&  voxel_pos.y <= 3) {
                    chunk.set(index, VOXELS::SAND);
                }
                else if(voxel_pos.y<h-3)
                {
                    chunk.set(index, VOXELS::STONE);
                }
                else if(voxel_pos.y<h-1)
                {
                    chunk.set(index, VOXELS::DIRT);
                }
                else if (voxel_pos.y < h) {
                    chunk.set(index, VOXELS::GRASS);
                } else if (voxel_pos.y <= 1) {
                    chunk.set(index, VOXELS::WATER);
                } else {
                    chunk.set(index, VOXELS::AIR);
                }
                index++;
            }
            voxel_pos.y=chunk_pos.y;
        }
        voxel_pos.z=chunk_pos.z;
    }
   // Log::debug("generate time:"+std::to_string(t.ms()));
}


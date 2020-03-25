//
// Created by User on 13-Mar.-2020.
//

#include "ChunkGenerator.h"
#include "Voxel.h"
#include "Chunk.h"
#include "VoxelDictionary.h"
#include <Utils/SimplexNoise.h>

void ChunkGenerator::generate(Chunk &chunk) {
    vec3 chunk_pos = vec3((chunk.position.x * Chunk::SIZE_X),
                          (chunk.position.y * Chunk::SIZE_Y),
                          (chunk.position.z * Chunk::SIZE_Z));
    vec3 voxel_pos = chunk_pos;
    /*
    int index = 0;
    for (int x = 0; x < Chunk::SIZE_X; ++x) {
        voxel_pos.x += 1;
        for (int z = 0; z < Chunk::SIZE_Z; ++z) {
            voxel_pos.z += 1;
            for (int y = 0; y < Chunk::SIZE_Y; ++y) {
                voxel_pos.y += 1;
                if ((x > 2 && x < 7) && (y > 2 && y < 7) && (z > 2 && z < 7)) {
                    chunk.set(index, VOXELS::GRASS);
                } else if (((x == 2 || x == 7))) {
                    chunk.set(index, VOXELS::GRASS);
                } else if (((z == 2 || z == 7))) {
                    chunk.set(index, VOXELS::GRASS);
                } else if (((y == 2 || y == 7))) {
                    chunk.set(index, VOXELS::GRASS);
                } else {
                    chunk.set(index, VOXELS::AIR);
                }

                index++;
            }
            voxel_pos.y = chunk_pos.y;
        }
        voxel_pos.z = chunk_pos.z;
    }*/

    float scale_layer_1 = 0.005;
    float scale_layer_2 = 0.01;
    float scale_layer_3 = 0.1;

    //float scale_caves=0.05;
    int index=0;
    for (int x = 0; x < Chunk::SIZE_X; ++x) {
        voxel_pos.x+=1;
        for (int z = 0; z < Chunk::SIZE_Z; ++z) {
            voxel_pos.z+=1;
            float layer_1=SimplexNoise::noise(voxel_pos.x * scale_layer_1, voxel_pos.z * scale_layer_1) *64;
            float layer_2=SimplexNoise::noise(voxel_pos.x* scale_layer_2, voxel_pos.z* scale_layer_2) *8;
            float layer_3=SimplexNoise::noise(voxel_pos.x * scale_layer_3, voxel_pos.z* scale_layer_3) *2;

            float h= layer_1+layer_2+layer_3;
            for (int y = 0; y < Chunk::SIZE_Y; ++y) {
                voxel_pos.y+=1;
                /*float cave=SimplexNoise::noise(voxel_pos.x*scale_caves,voxel_pos.y*scale_caves,voxel_pos.z*scale_caves);
                if(cave<-0.3&&voxel_pos.y<h)
                {
                    chunk.set(index, VOXELS::AIR);
                }
               else */if (voxel_pos.y < h &&  voxel_pos.y <= 3) {
                    chunk.set(index, VOXELS::SAND);
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

}


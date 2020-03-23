#pragma once

#include <API_ALL.h>
struct ChunkPosition{
    struct hash_fun {
        std::size_t operator()(const ChunkPosition &p) const {
            return std::hash<int>()(std::abs(((p.x * 64) + (p.y * 32) + (p.z))));
        }
    };
    int x,y,z;
    ChunkPosition(){};
    ChunkPosition(int x,int y,int z):x(x),y(y),z(z){};
    bool operator==(const ChunkPosition& other)const{
        return (x==other.x&&
                y==other.y&&
                z==other.z);
    }
    ChunkPosition operator-(const ChunkPosition& other)const{
        return ChunkPosition(x-other.x,y-other.y,z-other.z);
    }
};
struct Chunk{
    static const int SIZE_X =16;
    static const int SIZE_Y =64;
    static const int SIZE_Z =16;
    ChunkPosition position;
    bool empty=false;
    unsigned char data[SIZE_X*SIZE_Y*SIZE_Z];
    Chunk(int x,int y,int z);
    unsigned int index(int x,int y,int z);
    unsigned char at(int x,int y,int z);
    unsigned char at(unsigned int i);
    void set(int x,int y,int z, unsigned char value);
    void set(int i, unsigned char value);
    bool operator==(const Chunk& other)const{
        return (position==other.position);
    }
};
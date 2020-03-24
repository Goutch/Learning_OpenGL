#include "Chunk.h"
const float Chunk::RADIUS=sqrt((Chunk::SIZE_X*Chunk::SIZE_X)+(Chunk::SIZE_Y*Chunk::SIZE_Y)+(Chunk::SIZE_Z*Chunk::SIZE_Z))/2;
unsigned int Chunk::index(int x, int y, int z) {
    return (x * SIZE_Y * SIZE_Z) + (z * SIZE_Y) + y;
}

Chunk::Chunk(int x, int y, int z) {
    position.x=x;
    position.y=y;
    position.z=z;

}

unsigned char Chunk::at(int x, int y, int z) {
    return data[index(x,y,z)];
}

unsigned char Chunk::at(unsigned int i) {
    return data[i];
}

void Chunk::set(int x, int y, int z, unsigned char value) {
    data[index(x,y,z)]=value;
}

void Chunk::set(int i, unsigned char value) {
    data[i]=value;
}

#pragma once

#include <array>
#include "Drawable.h"
class Mesh :public Drawable{
private:
    enum MeshAttributeType{
        VERTICIES=0,
        NORMALS=1,
        UVS=2,
        CORLORS=3
    };
public:

    Mesh();
    Mesh& indices(unsigned int* indices, unsigned int indices_size);
    Mesh& vertices(float* vertices_array, unsigned int vertices_size);
    Mesh& normals(float* normals_array, unsigned int normals_size);
    Mesh& uvs(float* uvs_array, unsigned int uvs_size);
    Mesh& colors(float* colors_array,unsigned int colors_size);
};

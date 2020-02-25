#pragma once

#include <array>
#include "VAO.h"
struct Color;
class Mesh : public VAO{

public:
    enum MeshAttributeType{
        VERTICIES=0,
        UVS=1,
        NORMALS=2,
        CORLORS=3
    };
    Mesh();
    Mesh(std::string path);
    Mesh& indices(unsigned int* indices, unsigned int indices_count);
    Mesh& vertices(float* vertices_array, unsigned int vertices_count);
    Mesh& normals(float* normals_array, unsigned int normals_count);
    Mesh& uvs(float* uvs_array, unsigned int uvs_count);
    Mesh& colors(float* colors_array,unsigned int colors_count);
};

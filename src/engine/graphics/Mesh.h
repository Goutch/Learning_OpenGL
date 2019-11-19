#pragma once

#include "VAO.h"
#include <array>

class Mesh {
private:
    enum MeshAttributeType{
        INDICIES=0,
        VERTICIES=1,
        NORMALS=2,
        UVS=3,
        CORLORS=4
    };
    VAO vao;
    unsigned int vertex_count;
public:

    Mesh();
    ~Mesh();
    unsigned int vertexCount();
    void bind();
    void unbind();
    Mesh& vertices(float* vertices_array, unsigned int vertices_size);
    Mesh& colors(float* colors_array,unsigned int colors_size);
};

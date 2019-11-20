
#include "Mesh.h"
Mesh::~Mesh() {

}

Mesh::Mesh() {

}

Mesh &Mesh::vertices(float *vertices_array, unsigned int vertices_size) {
    vertex_count=vertices_size;
    vao.put(MeshAttributeType::VERTICIES, 3, vertices_array, vertices_size);
    return *this;
}

Mesh &Mesh::colors(float *colors_array, unsigned int colors_size) {
    vao.put(MeshAttributeType::CORLORS, 3, colors_array, colors_size);
    return *this;
}

void Mesh::bind() {
    vao.bind();
}

void Mesh::unbind() {
    vao.unbind();
}

unsigned int Mesh::vertexCount() {
    return vertex_count;
}

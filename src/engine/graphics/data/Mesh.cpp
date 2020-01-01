
#include "Mesh.h"

Mesh::Mesh():VAO() {
}
Mesh& Mesh::indices(unsigned int *indices, unsigned int indices_size) {
    indicies(indices,indices_size);
}
Mesh &Mesh::vertices(float *vertices_array, unsigned int vertices_size) {
    put(MeshAttributeType::VERTICIES, 3, vertices_array, vertices_size);
    return *this;
}
Mesh& Mesh::normals(float* normals_array, unsigned int normals_size)
{
    put(MeshAttributeType::NORMALS,3,normals_array,normals_size);
    return *this;
}
Mesh &Mesh::uvs(float *uvs_array, unsigned int uvs_size) {
    put(MeshAttributeType::UVS,2,uvs_array,uvs_size);
    return *this;
}
Mesh &Mesh::colors(float *colors_array, unsigned int colors_size) {
    put(MeshAttributeType::CORLORS, 3, colors_array, colors_size);
    return *this;
}




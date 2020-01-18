
#include "Mesh.h"
Mesh::Mesh():VAO() {
}
Mesh& Mesh::indices(unsigned int *indices, unsigned int indices_count) {
    indicies(indices,indices_count);
    return *this;
}
Mesh &Mesh::vertices(float *vertices_array, unsigned int vertices_count) {
    put(MeshAttributeType::VERTICIES, 3, vertices_array, vertices_count);
    return *this;
}
Mesh& Mesh::normals(float* normals_array, unsigned int normals_count)
{
    put(MeshAttributeType::NORMALS,3,normals_array,normals_count);
    return *this;
}
Mesh &Mesh::uvs(float *uvs_array, unsigned int uvs_count) {
    put(MeshAttributeType::UVS,2,uvs_array,uvs_count);
    return *this;
}
Mesh &Mesh::colors(float *colors_array, unsigned int colors_count) {
    put(MeshAttributeType::CORLORS, 4, colors_array, colors_count);
    return *this;
}





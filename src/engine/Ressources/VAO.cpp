#include "VAO.h"
#include "VBO.h"

#define GLEW_STATIC

#include <GL/glew.h>

VAO::VAO() {
    glGenVertexArrays(1, &vao_id);
}

VAO::~VAO() {
    for (const auto vbo:vbos) {
        delete vbo.second;
    }
    vbos.clear();
    glDeleteBuffers(1, &index_buffer_id);
    glDeleteVertexArrays(1, &vao_id);
}

void VAO::bind() const{
    glBindVertexArray(vao_id);

}

void VAO::unbind() const {
    glBindVertexArray(0);
}

void VAO::put(unsigned int atribute_position, unsigned int atribute_count_per_vertex, float *data, unsigned int data_count,bool is_static) {
    if(!has_index_buffer)
    {
        vertexCount=data_count/atribute_count_per_vertex;
    }
    glBindVertexArray(vao_id);
    if (vbos.find(atribute_position) == vbos.end())
        vbos.insert(std::pair<unsigned int, VBO *>(atribute_position,
                                                   new VBO(atribute_position, atribute_count_per_vertex, data, data_count,is_static)));
    else {
        delete vbos.at(atribute_position);
        vbos.at(atribute_position) = new VBO(atribute_position, atribute_count_per_vertex, data, data_count,is_static);
    }
    glBindVertexArray(0);
}

void VAO::indicies(unsigned int *indices, unsigned int indices_lenght) {
    glBindVertexArray(vao_id);
    if (!has_index_buffer)
    {
        glGenBuffers(1, &index_buffer_id);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_lenght * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
    has_index_buffer=true;
    vertexCount=indices_lenght;

}

unsigned int VAO::getVertexCount()  const{
    return vertexCount;
}

void VAO::set(unsigned int atribute_position, float *data, unsigned int data_count) {
    vbos.at(atribute_position)->set(data,data_count);
}

bool VAO::hasIndices() const{
    return has_index_buffer;
}


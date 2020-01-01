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

void VAO::bind() {
    glBindVertexArray(vao_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_buffer_id);
}

void VAO::unbind() {
    glBindVertexArray(0);
}

void VAO::put(unsigned int atribute_position, unsigned int atribute_size, float *data, unsigned int data_length) {
    glBindVertexArray(vao_id);
    if (vbos.find(atribute_position) == vbos.end())
        vbos.insert(std::pair<unsigned int, VBO *>(atribute_position,
                                                   new VBO(atribute_position, atribute_size, data, data_length)));
    else {
        delete vbos.at(atribute_position);
        vbos.at(atribute_position) = new VBO(atribute_position, atribute_size, data, data_length);
    }
    glBindVertexArray(0);
}

void VAO::indicies(unsigned int *indices, unsigned int indices_lenght) {
    glBindVertexArray(vao_id);
    if (has_index_buffer)
    {
        glDeleteBuffers(1, &index_buffer_id);
    }
    glGenBuffers(1, &index_buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_lenght * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
    has_index_buffer=true;
    vertexCount=indices_lenght;
}

unsigned int VAO::getVertexCount() {
    return vertexCount;
}


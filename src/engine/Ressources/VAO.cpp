#include "VAO.h"
#include "VBO.h"

#define GLEW_STATIC

#include <GL/glew.h>
#include <Utils/Timer.h>
#include <Core/Log.h>

VAO::VAO() {
    Timer t;
    glGenVertexArrays(1, &vao_id);
    Log::debug("new vao:"+std::to_string(vao_id));
    Log::debug("time:"+std::to_string(t.ms()));

}

VAO::~VAO() {
    for (const auto vbo:vbos) {
        delete vbo.second;
    }
    vbos.clear();
    glDeleteBuffers(1, &index_buffer_id);
    glDeleteVertexArrays(1, &vao_id);
}

void VAO::bind() const {
    glBindVertexArray(vao_id);

}

void VAO::unbind() const {
    glBindVertexArray(0);
}

void
VAO::put(unsigned int atribute_position, unsigned int atribute_count_per_vertex, float *data, unsigned int data_count,
         bool is_static) {
    Timer t;
    if (!has_index_buffer) {
        vertexCount = data_count / atribute_count_per_vertex;
    }
    glBindVertexArray(vao_id);
    if (vbos.find(atribute_position) == vbos.end())
    {
        vbos.insert(std::pair<unsigned int, VBO *>(atribute_position,
                                                   new VBO(atribute_position, atribute_count_per_vertex, data,
                                                           data_count, is_static)));
        Log::debug("new vbo:"+std::to_string(vbos.at(atribute_position)->getId()));
    }

    else {
        vbos.at(atribute_position)->set(data, data_count);
        Log::debug("set vbo:"+std::to_string(vbos.at(atribute_position)->getId()));
        // delete vbos.at(atribute_position);
        //vbos.at(atribute_position) = new VBO(atribute_position, atribute_count_per_vertex, data, data_count,is_static);
    }
    glBindVertexArray(0);
    Log::debug("time:"+std::to_string(t.ms()));
}
void VAO::put(unsigned int atribute_position, unsigned int atribute_count_per_vertex, unsigned int *data,
              unsigned int data_count, bool is_static) {
    Timer t;
    if (!has_index_buffer) {
        vertexCount = data_count / atribute_count_per_vertex;
    }
    glBindVertexArray(vao_id);
    if (vbos.find(atribute_position) == vbos.end())
    {

        vbos.insert(std::pair<unsigned int, VBO *>(atribute_position,
                                                   new VBO(atribute_position, atribute_count_per_vertex, data,
                                                           data_count, is_static)));
        Log::debug("new vbo:"+std::to_string(vbos.at(atribute_position)->getId()));
    }
    else {
        Log::debug("set vbo:"+std::to_string(vbos.at(atribute_position)->getId()));
        vbos.at(atribute_position)->set(data, data_count);
    }
    glBindVertexArray(0);
    Log::debug("time:"+std::to_string(t.ms()));
}
void VAO::indicies(unsigned int *indices, unsigned int indices_lenght, bool is_static) {
    Timer t;
    glBindVertexArray(vao_id);

    if (!has_index_buffer) {
        glGenBuffers(1, &index_buffer_id);
        Log::debug("new ebo:"+std::to_string(index_buffer_id));
    } else{
        Log::debug("set ebo:"+std::to_string(index_buffer_id));
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_lenght * sizeof(unsigned int), indices, is_static?GL_STATIC_DRAW:GL_DYNAMIC_DRAW);

    glBindVertexArray(0);
    has_index_buffer = true;
    vertexCount = indices_lenght;
    Log::debug("time:"+std::to_string(t.ms()));


}

void VAO::set(unsigned int atribute_position, float *data, unsigned int data_count) {
    vbos.at(atribute_position)->set(data, data_count);
}
void VAO::set(unsigned int atribute_position, unsigned int *data, unsigned int data_count) {
    vbos.at(atribute_position)->set(data, data_count);
}
void
VAO::put(unsigned int atribute_position, unsigned int atribute_count_per_vertex, int *data, unsigned int data_count,
         bool is_static) {
    if (!has_index_buffer) {
        vertexCount = data_count / atribute_count_per_vertex;
    }
    glBindVertexArray(vao_id);
    if (vbos.find(atribute_position) == vbos.end())
        vbos.insert(std::pair<unsigned int, VBO *>(atribute_position,
                                                   new VBO(atribute_position, atribute_count_per_vertex, data,
                                                           data_count, is_static)));
    else {
        vbos.at(atribute_position)->set(data, data_count);
        //vbos.at(atribute_position) = new VBO(atribute_position, atribute_count_per_vertex, data, data_count,is_static);
    }
    glBindVertexArray(0);
}

void VAO::set(unsigned int atribute_position, int *data, unsigned int data_count) {
    vbos.at(atribute_position)->set(data, data_count);
}

unsigned int VAO::getVertexCount() const {
    return vertexCount;
}


bool VAO::hasIndices() const {
    return has_index_buffer;
}








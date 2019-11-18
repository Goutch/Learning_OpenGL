#include "VAO.h"
#define GLEW_STATIC
#include <GL/glew.h>

VAO::VAO()
{
    glGenVertexArrays(1,&vao_id);
}
VAO::~VAO() {
    for(const auto vbo:vbos)
    {
        delete vbo.second;
    }
    vbos.clear();
}
void VAO::bind()
{
	glBindVertexArray(vao_id);
    for(const auto vbo:vbos)
    {
        vbo.second->bind();
    }
}
void VAO::unbind()
{
    for(const auto vbo:vbos)
    {
        vbo.second->unbind();
    }
	glBindVertexArray(0);
}

void VAO::put(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length) {
    glBindVertexArray(vao_id);
    vbos.insert(std::pair<unsigned int,VBO*>(atribute_position,new VBO(atribute_position,atribute_size,data,data_length)));
    glBindVertexArray(0);
}


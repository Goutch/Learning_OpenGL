#include "VBO.h"
#define GLEW_STATIC
#include <GL/glew.h>

VBO::VBO(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length) {
    glGenBuffers(1, &vbo_id);
    position=atribute_position;
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, data_length * sizeof(float), data, GL_STATIC_DRAW);
    glVertexAttribPointer(position, atribute_size, GL_FLOAT, GL_FALSE, atribute_size * sizeof(float) , nullptr);
    glEnableVertexAttribArray(position);

}
VBO::~VBO() {
    glDisableVertexAttribArray(position);
    glDeleteBuffers(1,&vbo_id);
}
void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
}
void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
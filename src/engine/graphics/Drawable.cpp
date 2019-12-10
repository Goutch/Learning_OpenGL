#include "Drawable.h"
Drawable::Drawable() {
    vao=new VAO;
}
Drawable::~Drawable() {
    delete vao;
}
void Drawable::bind() {
    vao->bind();
}
void Drawable::unbind() {
    vao->unbind();
}

unsigned int Drawable::vertexCount()
{
    return vertex_count;
}
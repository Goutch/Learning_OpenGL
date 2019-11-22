#pragma once

#include "VAO.h"
class Drawable {
protected:
    VAO* vao;
    unsigned int vertex_count;
public:
    Drawable();
    ~Drawable();
    virtual void bind();
    virtual void unbind();
    virtual unsigned int vertexCount();
};
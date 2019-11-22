#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "entities/Entity.h"
#include "graphics/Drawable.h"
#include "graphics/shaders/BaseShader.h"


void Renderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);
    for(auto &e:entities)
    {
        e->getShader().bind();
        e->getShader().loadEntityUniforms(*e);
        e->getDrawable().bind();
        glDrawElements(GL_TRIANGLES, e->getDrawable().vertexCount(), GL_UNSIGNED_INT, nullptr);
        e->getDrawable().unbind();
        e->getShader().unbind();
    }
    entities.clear();
}

void Renderer::addToRenderQueue(Entity* entity) {
    entities.push_back(entity);
}

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

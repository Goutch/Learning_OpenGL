#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "entities/Entity.h"
#include "graphics/Mesh.h"
#include "graphics/shaders/BaseShader.h"


void Renderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);
    for(auto &e:entities)
    {
        e->getShader().bind();
        e->getShader().loadEntityUniforms(*e);
        e->getMesh().bind();
        glDrawElements(GL_QUADS, e->getMesh().vertexCount(), GL_UNSIGNED_INT, nullptr);
        e->getMesh().unbind();
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

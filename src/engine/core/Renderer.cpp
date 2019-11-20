#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "entities/Entity.h"
#include "graphics/Mesh.h"
#include "graphics/shaders/ShaderProgram.h"

void Renderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);
    for(auto &e:entities)
    {
        e->getShader().bind();
        e->getMesh().bind();
        glDrawArrays(GL_QUADS, 0, e->getMesh().vertexCount());
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

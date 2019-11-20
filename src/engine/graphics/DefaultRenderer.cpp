//
// Created by User on 17-Nov.-2019.
//


#define GLEW_STATIC
#include <GL/glew.h>
#include "DefaultRenderer.h"

DefaultRenderer::DefaultRenderer() {

}
DefaultRenderer::~DefaultRenderer() {

}

void DefaultRenderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);
    for(auto &e:entities)
    {
        e.getShader().bind();
        e.getMesh().bind();
        glDrawArrays(GL_QUADS, 0, e.getMesh().vertexCount());
        e.getMesh().unbind();
        e.getShader().unbind();
    }
    entities.clear();
}

void DefaultRenderer::addToRenderQueue(Entity& entity) {
    entities.push_back(entity);
}









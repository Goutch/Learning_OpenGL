//
// Created by User on 17-Nov.-2019.
//


#define GLEW_STATIC
#include <GL/glew.h>
#include "DefaultRenderer.h"

DefaultRenderer::DefaultRenderer() {

}
DefaultRenderer::~DefaultRenderer() {}

void DefaultRenderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto vao:objects)
    {
        vao->bind();
        glDrawArrays(GL_QUADS, 0, 4);
        vao->unbind();
    }
    objects.clear();
}

void DefaultRenderer::addToRenderQueue(VAO* objectVAO) {
    objects.push_back(objectVAO);
}





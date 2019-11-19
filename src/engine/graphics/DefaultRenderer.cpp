//
// Created by User on 17-Nov.-2019.
//


#define GLEW_STATIC
#include <GL/glew.h>
#include "DefaultRenderer.h"

DefaultRenderer::DefaultRenderer() {
    shader =new ShaderProgram("../src/engine/graphics/shaders/shadersSources/BaseVertex.glsl", "../src/engine/graphics/shaders/shadersSources/BaseFragment.glsl");
}
DefaultRenderer::~DefaultRenderer() {
    delete shader;
}

void DefaultRenderer::render() {
    shader->bind();
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto mesh:objects)
    {
        mesh->bind();
        glDrawArrays(GL_QUADS, 0, mesh->vertexCount());
        mesh->unbind();
    }
    shader->unbind();
    objects.clear();
}

void DefaultRenderer::addToRenderQueue(Mesh* mesh) {
    objects.push_back(mesh);
}





//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "core/Renderer.h"
#include "graphics/data/VAO.h"
#include "core/Scene.h"
MeshRenderer::MeshRenderer(VAO &mesh, EntityShader &shader, vec3 position, vec3 rotation, vec3 scale):Entity(position,rotation,scale) {
    this->mesh=&mesh;
    this->shader=&shader;
}

void MeshRenderer::render(Scene &scene) {
    scene.getRenderer().addToRenderQueue(*this);
}

EntityShader &MeshRenderer::getShader() {
    return *shader;
}

VAO &MeshRenderer::getVAO()  {
    return *mesh;
}


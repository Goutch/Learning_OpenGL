//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "core/Renderer.h"
#include "graphics/data/VAO.h"

MeshRenderer::MeshRenderer(VAO &mesh, EntityShader &shader, vec3 position, vec3 rotation, vec3 scale):Entity(position,rotation,scale) {
    this->mesh=&mesh;
    this->shader=&shader;
}

void MeshRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(*this);
}

void MeshRenderer::update(float delta, Window &window) {

}

EntityShader &MeshRenderer::getShader() {
    return *shader;
}

VAO &MeshRenderer::getVAO()  {
    return *mesh;
}


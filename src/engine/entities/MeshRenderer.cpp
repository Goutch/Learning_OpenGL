//
// Created by User on 19-Nov.-2019.
//

#include "graphics/Mesh.h"
#include "graphics/shaders/ShaderProgram.h"
#include "MeshRenderer.h"
#include "core/Renderer.h"
MeshRenderer::MeshRenderer(Mesh &mesh,ShaderProgram& shader, glm::vec3 pos) {
    transform.translate(pos);
    this->mesh=&mesh;
    this->shader=&shader;
}

void MeshRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(this);
}

void MeshRenderer::update(float delta, Window &window) {

}

ShaderProgram &MeshRenderer::getShader() {
    return *shader;
}

Transform &MeshRenderer::getTranform() {
    return transform;
}

Mesh &MeshRenderer::getMesh() {
    return *mesh;
}
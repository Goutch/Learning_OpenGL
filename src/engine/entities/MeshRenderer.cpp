//
// Created by User on 19-Nov.-2019.
//

#include "MeshRenderer.h"
MeshRenderer::MeshRenderer(Mesh &mesh,ShaderProgram& shader, glm::vec3 pos) {
    transform.translate(pos);
    this->mesh=&mesh;
    this->shader=&shader;
}

void MeshRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(transform,mesh,shader);
}

void MeshRenderer::update(float delta, Window &window) {

}

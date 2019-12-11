//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "core/Renderer.h"
#include "graphics/Mesh.h"
MeshRenderer::MeshRenderer(Mesh* mesh, EntityShader* shader, glm::vec3 pos):Entity(pos) {
    this->mesh=mesh;
    this->shader=shader;
}

void MeshRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(this);
}

void MeshRenderer::update(float delta, Window &window) {

}

EntityShader &MeshRenderer::getShader() {
    return *shader;
}

Drawable &MeshRenderer::getDrawable()  {
    return *mesh;
}
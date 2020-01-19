//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "Core/Renderer.h"
#include "Geometry/VAO.h"
#include "Core/Scene.h"
MeshRenderer::MeshRenderer(VAO &mesh, Material &shader, vec3 position, vec3 rotation, vec3 scale): Entity(position, rotation, scale) {
    this->mesh=&mesh;
    this->m=&shader;
}

MeshRenderer::MeshRenderer(VAO &mesh, Material &material): Entity() {
    this->mesh=&mesh;
    this->m=&material;
}

void MeshRenderer::render(Scene &scene) {
    scene.getRenderer().addToRenderQueue(*this);
}

Material &MeshRenderer::material() {
    return *m;
}

VAO &MeshRenderer::getVAO()  {
    return *mesh;
}




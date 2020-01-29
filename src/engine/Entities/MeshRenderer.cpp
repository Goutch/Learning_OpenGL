//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Geometry/VAO.h"
#include "Core/Scene.h"
MeshRenderer::MeshRenderer(const VAO &mesh, Material &material, vec3 position, vec3 rotation, vec3 scale): Entity(position, rotation, scale) {
    this->mesh=&mesh;
    this->m=&material;
}

MeshRenderer::MeshRenderer(const VAO &mesh, Material &material): Entity() {
    this->mesh=&mesh;
    this->m=&material;
}

void MeshRenderer::render(const Scene &scene) const{
    scene.getRenderer().addToRenderQueue(*mesh,*m,transform);
}




//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Ressources/VAO.h"
#include "Core/Scene.h"
MeshRenderer::MeshRenderer(const VAO &mesh,const  SpacialMaterial &material, vec3 position, vec3 rotation, vec3 scale): SpacialEntity(position, rotation, scale) {
    this->mesh=&mesh;
    this->m=&material;
}

MeshRenderer::MeshRenderer(const VAO &mesh,const  SpacialMaterial &material): SpacialEntity() {
    this->mesh=&mesh;
    this->m=&material;
}

void MeshRenderer::draw(const SpacialScene &scene) const {
    SpacialEntity::draw(scene);
    scene.getRenderer().draw(*mesh, *m, transform);
}






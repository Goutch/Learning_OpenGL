//
// Created by User on 19-Nov.-2019.
//



#include "MeshRenderer.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Ressources/VAO.h"
#include "Core/Scene.h"
MeshRenderer::MeshRenderer(vec3 position, vec3 rotation, vec3 scale) : Entity(position, rotation, scale) {

}
MeshRenderer::MeshRenderer(const VAO &mesh, const  EntityMaterial &material, vec3 position, vec3 rotation, vec3 scale): Entity(position, rotation, scale) {
    this->mesh=&mesh;
    this->m=&material;
}

MeshRenderer::MeshRenderer(const VAO &mesh,const  EntityMaterial &material): Entity() {
    this->mesh=&mesh;
    this->m=&material;
}

void MeshRenderer::draw(const Scene &scene) const {
    Entity::draw(scene);
    scene.getRenderer().draw(*mesh, *m, transform);
}










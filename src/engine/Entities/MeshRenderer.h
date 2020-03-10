#pragma once

#include <Core/Scene.h>
#include "Entity.h"
class EntityMaterial;
class Mesh;
class VAO;
class MeshRenderer :public Entity{
    const EntityMaterial* m;
    const VAO* mesh;
public:
    MeshRenderer(const VAO& mesh, const EntityMaterial& material, vec3 position, vec3 rotation=vec3(0), vec3 scale=vec3(1));
    MeshRenderer(const VAO& mesh, const EntityMaterial& material);

    void draw(const Scene &scene) const override;

};



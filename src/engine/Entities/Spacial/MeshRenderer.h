#pragma once

#include <Core/SpacialScene.h>
#include "SpacialEntity.h"
class SpacialMaterial;
class Mesh;
class VAO;
class MeshRenderer :public SpacialEntity{
    const SpacialMaterial* m;
    const VAO* mesh;
public:
    MeshRenderer(const VAO& mesh, const SpacialMaterial& material, vec3 position, vec3 rotation=vec3(0), vec3 scale=vec3(1));
    MeshRenderer(const VAO& mesh, const SpacialMaterial& material);

    void draw(const SpacialScene &scene) const override;

};



#pragma once

#include "Entity.h"
class Material;
class Mesh;
class MeshRenderer :public Entity{
    Material* m;
    const VAO* mesh;
public:
    MeshRenderer(const VAO& mesh,Material& material, vec3 position, vec3 rotation=vec3(0), vec3 scale=vec3(1));
    MeshRenderer(const VAO& mesh, Material& material);

    void draw(const Scene& scene)const override ;
};



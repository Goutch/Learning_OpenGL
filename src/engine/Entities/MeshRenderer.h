#pragma once

#include "Entity.h"
class Material;
class Mesh;
class MeshRenderer :public Entity{
    Material* m;
    VAO* mesh;
public:
    MeshRenderer(VAO& mesh, Material& material, vec3 position, vec3 rotation, vec3 scale);
    MeshRenderer(VAO& mesh, Material& material);

    Material &material();

    VAO &getVAO();

    void render(Scene& scene) override ;
};



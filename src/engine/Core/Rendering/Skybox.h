#pragma once

#include <Ressources/AtlasTexture.h>
#include <Ressources/Mesh.h>
#include <Ressources/Shaders/Material/EntityMaterial.h>
#include <Entities/Transform.h>

class Skybox {
    Transform transform;
    EntityMaterial material;
    Mesh mesh;

public:
    Mesh& getMesh();
    EntityMaterial& getMaterial();

    Skybox(AtlasTexture& texture,const Shader& shader);

    Transform& getTransform();
};



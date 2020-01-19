#pragma once

#include <vector>

#include <Shaders/Shader.h>
#include <Data/Texture.h>
#include <Geometry/Mesh.h>
#include "Core/Scene.h"
#include <Shaders/Material.h>
#include "Entities/Entity.h"
class RandomCubes : public Scene {
private:
    Shader shader=Shader("../src/engine/Shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Shaders/shadersSources/EntityFragment.glsl");
    Material material;

    Mesh mesh;
    Texture stone;

public:
    RandomCubes();

    ~RandomCubes();

    void init(Window &window,Renderer &renderer) override;

    void update(float delta) override ;
};



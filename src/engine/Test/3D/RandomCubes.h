#pragma once

#include <vector>

#include <Geometry/shaders/Shader.h>
#include <Geometry/data/Texture.h>
#include <Geometry/Mesh.h>
#include "core/Scene.h"
#include <Geometry/Material.h>
#include "entities/Entity.h"
class RandomCubes : public Scene {
private:
    Shader shader=Shader("../src/engine/Geometry/shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Geometry/shaders/shadersSources/EntityFragment.glsl");
    Material material;
    Entity* camera;
    Mesh mesh;
    Texture stone;

public:
    RandomCubes();

    ~RandomCubes();

    void init(Window &window,Renderer &renderer) override;

    void update(float delta) override ;
};



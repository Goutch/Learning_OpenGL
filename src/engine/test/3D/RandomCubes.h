#pragma once

#include <vector>
#include <graphics/data/Sprite.h>
#include <graphics/shaders/Shader.h>
#include <graphics/data/Texture.h>
#include <graphics/data/Mesh.h>
#include "core/Scene.h"
#include <graphics/Material.h>
#include "entities/Entity.h"
class RandomCubes : public Scene {
private:
    Shader shader=Shader("../src/engine/graphics/shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/graphics/shaders/shadersSources/EntityFragment.glsl");
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



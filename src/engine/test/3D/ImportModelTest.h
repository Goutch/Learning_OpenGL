#pragma once


#include <graphics/data/Sprite.h>
#include <graphics/shaders/Shader.h>
#include <graphics/Material.h>
#include <graphics/data/Texture.h>
#include <graphics/data/Mesh.h>
#include "core/Scene.h"
class ImportModelTest: public Scene {
private:
    Shader shader=Shader("../src/engine/graphics/shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/graphics/shaders/shadersSources/EntityFragment.glsl");
    Material material;
    Mesh mesh;
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

    void render() override;
};

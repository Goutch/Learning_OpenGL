#pragma once


#include <graphics/shaders/Shader.h>
#include <graphics/Material.h>
#include <graphics/data/Texture.h>
#include <Geometry/Mesh.h>
#include "core/Scene.h"
class ImportModelTest: public Scene {
private:
    Shader shader=Shader("../src/engine/Geometry/shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Geometry/shaders/shadersSources/EntityFragment.glsl");
    Material material;
    Mesh mesh;
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

    void render() override;
};
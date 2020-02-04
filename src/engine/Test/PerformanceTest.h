#pragma once

#include <vector>

#include <Shaders/Shader.h>
#include <Data/Texture.h>
#include <Geometry/Mesh.h>
#include "Core/Scene.h"
#include <Shaders/Material.h>
#include "Entities/Entity.h"
class PerformanceTest : public Scene {
private:
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                         "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Material material=Material(shader,stone);

    Mesh mesh;
    Texture stone= Texture("../res/stone.jpg", false);

public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

};



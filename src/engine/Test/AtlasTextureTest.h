#pragma once

#include "Core/Scene.h"
#include "Geometry/VAO.h"
#include "Data/AtlasTexture.h"
#include "Shaders/Shader.h"
#include "Shaders/Material.h"
#include "Entities/Transform.h"

class AtlasTextureTest : public Scene {
private:
    VAO sprite;
    AtlasTexture spriteSheet;
    Shader shader = Shader("../src/engine/Shaders/shadersSources/EntityVertex.glsl",
                           "../src/engine/Shaders/shadersSources/EntityFragment.glsl");
    Material material;

public:
    void init(Window &window, Renderer &renderer) override;


};

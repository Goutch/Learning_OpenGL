#pragma once

#include "Core/Scene.h"
#include "Geometry/Mesh.h"
#include "Data/AtlasTexture.h"
#include "Shaders/Shader.h"
#include "Shaders/Material.h"
#include "Entities/Transform.h"

class AtlasTextureTest : public Scene {
private:
    Mesh mesh;
    AtlasTexture spriteSheet;
    Shader shader = Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                           "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Material material=Material(shader,spriteSheet);

public:
    void init(Window &window, Renderer &renderer) override;


};

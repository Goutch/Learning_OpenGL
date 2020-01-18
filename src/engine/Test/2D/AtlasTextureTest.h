#pragma once
#include "core/Scene.h"
#include "Geometry/VAO.h"
#include "graphics/data/AtlasTexture.h"
#include "graphics/shaders/Shader.h"
#include "graphics/Material.h"
#include "entities/Transform.h"
class AtlasTextureTest: public Scene {
private:
    VAO sprite;
    AtlasTexture spriteSheet;
    Shader shader=Shader("../src/engine/Geometry/shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Geometry/shaders/shadersSources/EntityFragment.glsl");
    Material material;
    Transform camera;
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

};
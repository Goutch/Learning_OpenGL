#pragma once
#include "core/Scene.h"
#include "graphics/data/Sprite.h"
#include "graphics/data/AtlasTexture.h"
#include "graphics/shaders/EntityShader.h"
#include "entities/Transform.h"
class AtlasTextureTest: public Scene {
private:
    Sprite sprite;
    AtlasTexture spriteSheet;
    EntityShader shader;
    Transform camera;
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

};

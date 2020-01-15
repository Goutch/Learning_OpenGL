#pragma once


#include <graphics/data/Sprite.h>
#include <graphics/shaders/EntityShader.h>
#include <graphics/data/Texture.h>
#include <graphics/data/Mesh.h>
#include "core/Scene.h"
class ImportModelTest: public Scene {
private:
    EntityShader* shader;
    Mesh* mesh;
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

    void render() override;
};

#pragma once

#include <vector>
#include <graphics/data/Sprite.h>
#include <graphics/shaders/EntityShader.h>
#include <graphics/data/Texture.h>
#include <graphics/data/Mesh.h>
#include "core/Game.h"
class Test : public Game {
private:
    std::vector<Entity*> entities;
    EntityShader* shader;
    Window* window;
    Renderer* renderer;
    Mesh* mesh;

public:
    Test();

    ~Test();

    void init(Window &window,Renderer &renderer) override;

    void update() override;

    void render() override;
};



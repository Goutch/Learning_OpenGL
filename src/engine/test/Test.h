#pragma once
#include <vector>
#include "core/Game.h"
#include "core/Window.h"
#include "entities/Entity.h"

class Test :  public Game{
private:
    std::vector<Entity *> entities;
    Mesh quad;
    ShaderProgram shader=ShaderProgram("../src/engine/graphics/shaders/shadersSources/BaseVertex.glsl", "../src/engine/graphics/shaders/shadersSources/BaseFragment.glsl");
public:
    Test();
    ~Test();
    void init() override;

    void update(Window &window) override;

    void render(Renderer &renderer) override;
};



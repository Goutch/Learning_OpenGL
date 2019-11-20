#pragma once

#include <vector>
#include "core/Game.h"
class BaseShader;
class Mesh;

class Window;

class Entity;

class Test : public Game {
private:
    std::vector<Entity *> entities;
    Mesh* quad;
    BaseShader* shader;
public:
    Test();

    ~Test();

    void init() override;

    void update(Window &window) override;

    void render(Renderer &renderer) override;
};



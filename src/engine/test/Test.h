#pragma once

#include <vector>
#include "core/Game.h"
class EntityShader;
class Mesh;
class Window;
class Entity;
class Sprite;
class Texture;
#include "entities/Camera.h"
class Test : public Game {
private:
    std::vector<Entity *> entities;
    Mesh* quad;
    EntityShader* shader;
    Sprite* sprite;
    Texture* wall;
    Texture* stone;
    Window* window;
    Renderer* renderer;
    Camera camera=Camera(vec3(0,0,0));
public:
    Test();

    ~Test();

    void init(Window &window,Renderer &renderer) override;

    void update() override;

    void render() override;
};



#pragma once

#include "Game.h"

class Engine {
private:
    Window* window;
    Renderer* renderer;
public:
    Engine();
    ~Engine();
    void start(Game& game);
};


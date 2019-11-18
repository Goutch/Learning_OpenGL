#pragma once

#include <engine/core/Game.h>

class Test :  public Game{
private:
    std::array<VAO *, 10> vaos;
public:
    Test();
    ~Test();
    void init() override;

    void update(Window &window) override;

    void render(Renderer &renderer) override;
};



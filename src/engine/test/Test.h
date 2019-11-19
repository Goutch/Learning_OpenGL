#pragma once

#include <engine/core/Game.h>
#include <vector>
#include <engine/graphics/Mesh.h>

class Test :  public Game{
private:
    std::vector<Mesh *> objects;
public:
    Test();
    ~Test();
    void init() override;

    void update(Window &window) override;

    void render(Renderer &renderer) override;
};



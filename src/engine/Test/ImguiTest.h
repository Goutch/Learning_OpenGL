#pragma once

#include <Core/Scene.h>

class ImguiTest: public Scene {
    mutable Color color;
public:
    void init(const Canvas &canvas, Renderer &renderer, Window &window) override;

    void draw() const override;
};


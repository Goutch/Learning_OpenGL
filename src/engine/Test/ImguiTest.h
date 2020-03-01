#pragma once

#include <Core/Scene.h>

class ImguiTest: public Scene {
    mutable Color color;
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    void draw() const override;
};


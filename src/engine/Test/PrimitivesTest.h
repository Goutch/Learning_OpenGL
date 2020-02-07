#pragma once

#include <Core/Scene.h>
#include <Shaders/Canvas/CanvasMaterial.h>

class PrimitivesTest: public Scene {
public:
    CanvasMaterial material;
    void init(const Canvas &canvas, Renderer &renderer, Window &window) override;

public:

};


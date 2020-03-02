#pragma once

#include <Shaders/Canvas/CanvasMaterial.h>
#include "CanvasEntity.h"

class Rect: public CanvasEntity {
    Color color;
public:
    Rect(glm::vec2 position,glm::vec2 size,const Color color);
    void draw(const Scene &scene) const override;
};


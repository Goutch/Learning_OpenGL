#pragma once

#include <Shaders/Canvas/CanvasMaterial.h>
#include "CanvasEntity.h"

class Rect: public CanvasEntity {
    const CanvasMaterial* material;
public:
    Rect(vec2 position,vec2 size,const CanvasMaterial& material);
    void draw(const Scene &scene) const override;
};


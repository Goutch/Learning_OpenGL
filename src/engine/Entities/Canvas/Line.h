#pragma once


#include "CanvasEntity.h"

class CanvasMaterial;

class Line: public CanvasEntity {
    const CanvasMaterial* material;
public:
    Line(vec2 point1,vec2 point2, float width,const CanvasMaterial& material);
    void draw(const Scene &scene) const override;
};



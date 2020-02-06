#pragma once


#include "CanvasEntity.h"

class CanvasMaterial;

class Line: public CanvasEntity {
    const CanvasMaterial* material;
    Line(float x1, float y1, float x2, float y2, float width,const CanvasMaterial& material);

public:
    void draw(const Scene &scene) const override;
};



//
// Created by User on 05-Feb.-2020.
//

#include "Line.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Scene.h>
#include <Shaders/Canvas/CanvasMaterial.h>
Line::Line(float x1, float y1, float x2, float y2, float width, const CanvasMaterial &material) :CanvasEntity(){
    this->material= &material;
    float deltaX = x2 - x1;
    float deltaY = y2 - y1;
    float x = x1 + (deltaX / 2);
    float y = y1 + (deltaY / 2);
    float lenght = (float) sqrt((deltaX * deltaX) + (deltaY * deltaY)) + (width * 2);
    float rot = atan(deltaY, deltaX);
    transform.translate(vec2(x, y));
    transform.rotate(rot);
    transform.scale(vec2(lenght, width));
}
void Line::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    const Renderer& r=scene.getRenderer();
    r.draw(r.QUAD,transform,*material);
}
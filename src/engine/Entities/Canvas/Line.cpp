//
// Created by User on 05-Feb.-2020.
//

#include "Line.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Scene.h>
#include <Shaders/Canvas/CanvasMaterial.h>
Line::Line(vec2 point1,vec2 point2, float width, const CanvasMaterial &material) :CanvasEntity(){
    this->material= &material;
    vec2 delta = point2 - point1;
    float x = point1.x + (delta.x / 2);
    float y = point1.y + (delta.y / 2);
    float lenght = (float) sqrt((delta.x* delta.x) + (delta.y * delta.y)) + (width );
    float rot = atan(delta.y, delta.x);
    transform.translate(vec2(x, y));
    transform.rotate(rot);
    transform.scale(vec2(lenght, width));
}
void Line::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    const Renderer& r=scene.getRenderer();
    r.draw(r.QUAD, transform, *material);
}
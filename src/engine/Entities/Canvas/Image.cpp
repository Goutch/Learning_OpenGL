//
// Created by le6mon on 2020-03-03.
//

#include "Image.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

Image::Image(const vec2 &position, float rotation, const vec2 &scale, CanvasMaterial *canvasMaterial) : CanvasEntity(
        position, rotation, scale), canvasMaterial(canvasMaterial) {}

void Image::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    scene.getRenderer().draw(scene.getRenderer().QUAD, this->transform, *canvasMaterial);
}

//
// Created by le6mon on 2020-03-02.
//

#include "Ellipse.h"
#include "CanvasEntity.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

Ellipse::Ellipse(vec2 position, vec2 size, Color color): CanvasEntity(position, 0, size) {
    this->color = color;
}

void Ellipse::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    scene.getRenderer().drawEllipse(this->transform.position()[0], this->transform.position()[1], this->transform.scale()[0], this->transform.scale()[1], color);
}
//
// Created by User on 05-Feb.-2020.
//

#include "Rect.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Scene.h>

Rect::Rect(vec2 position, vec2 size, const Color color):CanvasEntity(position,0,size) {
    this->color = color;
}

void Rect::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    scene.getRenderer().drawRect(this->transform.position()[0], this->transform.position()[1], this->transform.scale()[0], this->transform.scale()[1], color);
}




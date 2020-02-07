//
// Created by User on 05-Feb.-2020.
//

#include "Rect.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Scene.h>

Rect::Rect(vec2 position, vec2 size, const CanvasMaterial &material):CanvasEntity(position,0,size) {
    this->material=&material;
}

void Rect::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    const Renderer& r=scene.getRenderer();
    r.draw(r.QUAD, transform, *material);
}



//
// Created by Simon on 2020-02-04.
//

#include "LAB3.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Viewport.h>

void LAB3::render() const {
    Scene::render();
    float w=viewport->getPixelWidth();
    float h=viewport->getPixelHeight();
    renderer->drawRect(w/2, h/2, w, h, Color::WHITE);
    renderer->drawRect(w/2, h/2, 500, 500, Color::BLACK);
    renderer->drawRect(w/2, h/2, 500 - 50, 500 - 50, Color::WHITE);
}

void LAB3::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);

    addEntity(new Text)
}
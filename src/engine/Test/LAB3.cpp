//
// Created by Simon on 2020-02-04.
//

#include "LAB3.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Canvas.h>
#include "Entities/Canvas/Text.h"
#include <Geometry/Geometry.h>
#include <Entities/Spacial/MeshRenderer.h>
#include <Core/Window.h>
#include <Entities/Spacial/Camera.h>

void LAB3::render() const {
    Scene::render();
    float w=canvas->getPixelWidth();
    float h=canvas->getPixelHeight();
    //renderer->drawRect(w/2, h/2, 500, 500, Color::WHITE);
    //renderer->drawRect(w/2, h/2, 500 - 50, 500 - 50, Color::BLACK);
    //renderer->drawRect(w/2 - 50, h/2 - 330, 500 - 25, 500 - 25, Color::BLACK);
    //renderer->drawRect(w/2 - 75, h/2 - 195, 500 - 25, 148, Color::RED);
}

void LAB3::init(Canvas &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);

    CanvasEntity* e= new Text("Your", vec3(viewport.getPixelWidth() / 2 - 300, viewport.getPixelHeight() / 2 - 200, 0), font, 64);
    CanvasEntity* t= new Text("Company", vec3(viewport.getPixelWidth() / 2 - 300, viewport.getPixelHeight() / 2 - 264, 0), font, 64);
    addEntity(e);
    addEntity(t);
}

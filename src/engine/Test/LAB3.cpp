//
// Created by Simon on 2020-02-04.
//

#include "LAB3.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Viewport.h>
#include "Entities/Text.h"
#include <Geometry/Geometry.h>
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>
#include <Entities/Camera.h>

void LAB3::render() const {
    Scene::render();
    camera->setProjectionMode(Camera::ProjectionMode::ORTHOGRAPHIC_UNITS);
    float w=viewport->getPixelWidth();
    float h=viewport->getPixelHeight();
    renderer->drawRect(w/2, h/2, w, h, Color::BLACK);
    renderer->drawEllipse(w/2 + 50, h/2 + 50, 500, 500, Color::RED);
    renderer->drawRect(w/2, h/2, 500, 500, Color::WHITE);
    renderer->drawRect(w/2, h/2, 500 - 50, 500 - 50, Color::BLACK);
    renderer->drawRect(w/2 - 50, h/2 - 330, 500 - 25, 500 - 25, Color::BLACK);
    renderer->drawRect(w/2 - 75, h/2 - 195, 500 - 25, 148, Color::RED);
    renderer->drawLine(w/2 + 230, h/2 - 330, w/2 + 475, h/2 - 330, 3, Color::RED);
}

void LAB3::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);

    Entity* e= new Text("Your", vec3(viewport.getPixelWidth() / 2 - 300, viewport.getPixelHeight() / 2 - 200, 0), font, 64);
    Entity* t= new Text("Company", vec3(viewport.getPixelWidth() / 2 - 300, viewport.getPixelHeight() / 2 - 264, 0), font, 64);

    Entity* smallText= new Text("Made with OpenGL", vec3(viewport.getPixelWidth() / 2 + 225, viewport.getPixelHeight() / 2 - 330, 0), font2, 16);
    addEntity(e);
    addEntity(t);
    addEntity(smallText);
}

//
// Created by Simon on 2020-02-04.
//

#include "LAB3.h"
#include <Core/Rendering/Renderer.h>

#include "Entities/Canvas/Text.h"
#include <Geometry/Geometry.h>

#include <Core/Window.h>

#include <Core/Canvas.h>

void LAB3::draw() const {
    float w = canvas->getPixelWidth();
    float h = canvas->getPixelHeight();
    renderer->drawRect(w / 2, h / 2, w, h, Color::BLACK);
    renderer->drawEllipse(w / 2 + 50, h / 2 + 50, 500, 500, Color::RED);
    renderer->drawRect(w / 2, h / 2, 500, 500, Color::WHITE);
    renderer->drawRect(w / 2, h / 2, 500 - 50, 500 - 50, Color::BLACK);
    renderer->drawRect(w / 2 - 50, h / 2 - 330, 500 - 25, 500 - 25, Color::BLACK);
    renderer->drawRect(w / 2 - 75, h / 2 - 195, 500 - 25, 148, Color::RED);
    renderer->drawLine(w / 2 + 230, h / 2 - 330, w / 2 + 475, h / 2 - 330, 3, Color::RED);
    Scene::draw();

}

void LAB3::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    addEntity(new Text("Your", vec2(canvas.getPixelWidth() / 2 - 300, canvas.getPixelHeight() / 2 - 200), font, 64));
    addEntity(new Text("Company", vec2(canvas.getPixelWidth() / 2 - 300, canvas.getPixelHeight() / 2 - 264), font, 64));
    //small text
    addEntity(new Text("Made with OpenGL", vec2(canvas.getPixelWidth() / 2 + 225, canvas.getPixelHeight() / 2 - 330),
                       font2, 16));
}



//
// Created by Simon on 2020-02-10.
//

#include "LAB4.h"
#include "Core/Rendering/Renderer.h"
#include <Core/Canvas.h>
#include "Entities/Canvas/Line.h"

int maxGen = 1;
void LAB4::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    float w = canvas.getPixelWidth();
    float h = canvas.getPixelHeight();
    addEntity(new Line(vec2(w/2, h/2) , vec2(w/2, 50), 4, material));
}

void LAB4::draw() const {
    Scene::draw();
    float w = canvas->getPixelWidth();
    float h = canvas->getPixelHeight();
    renderer->drawLine(w/2, h/2, w/2, 50, 4, Color::RED);
}

void LAB4::fractale(float lastX, float lastY, int gen) {
    if(gen == maxGen + 1)
        return;

    float newX = lastX;
    float newY = lastY + 10;
    addEntity(new Line(vec2(lastX, lastY) , vec2(newX, newY), 4/(gen/4 + 1), material));
    fractale(newX, newY, gen + 1);
}

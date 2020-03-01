//
// Created by Simon on 2020-02-10.
//

#include "LAB4.h"
#include "Core/Rendering/Renderer.h"
#include <Core/Canvas.h>
#include "Entities/Canvas/Line.h"

int maxGen = 8;
void LAB4::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    float w = canvas.getPixelWidth();
    float h = canvas.getPixelHeight();
    fractale(w/2,0,1);
}

void LAB4::draw() const {
    Scene::draw();
}

void LAB4::fractale(float lastX, float lastY, int gen) {
    if(gen == maxGen + 1)
        return;

    float newX = lastX + 200*(1.0f/gen);
    float newY = lastY + 200*(1.0f/gen);
    addEntity(new Line(vec2(lastX, lastY) , vec2(newX, newY), ((float)maxGen + 1 - gen)/maxGen*3 + 1, material));
    fractale(newX, newY, gen + 1);
    float newX2 = lastX - 200*(1.0f/gen);
    float newY2 = lastY + 200*(1.0f/gen);
    addEntity(new Line(vec2(lastX, lastY) , vec2(newX2, newY2), ((float)maxGen + 1 - gen)/maxGen*3 + 1, material));
    fractale(newX2, newY2, gen + 1);
}

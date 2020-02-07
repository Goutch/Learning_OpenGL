//
// Created by User on 02-Feb.-2020.
//

#include "PrimitivesTest.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Canvas.h>
#include <Entities/Canvas/Line.h>
#include <Entities/Canvas/Rect.h>

void PrimitivesTest::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    material.setShader(renderer.DEFAULT_CANVAS_SHADER);
    material.setColor(Color::RED);
    addEntity(new Rect(vec2(canvas.getPixelWidth()/2,canvas.getPixelHeight()/2),vec2(canvas.getPixelWidth(),canvas.getPixelHeight()),material));
    addEntity(new Rect(vec2(canvas.getPixelWidth()/2,canvas.getPixelHeight()/2),vec2(canvas.getPixelWidth()/2,canvas.getPixelHeight()/2),renderer.DEFAULT_CANVAS_MATERIAL));

}

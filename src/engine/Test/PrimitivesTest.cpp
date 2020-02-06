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
    addEntity(new Line(vec2(0,0),vec2(canvas.getPixelWidth(),canvas.getPixelHeight()),2,renderer.DEFAULT_CANVAS_MATERIAL));
    addEntity(new Rect(vec2(505,300),vec2(200,200),renderer.DEFAULT_CANVAS_MATERIAL));
}

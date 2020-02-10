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
    float w=canvas.getPixelWidth();
    float h=canvas.getPixelHeight();
    addEntity(new Line(
            vec2(0,0),
            vec2((w/2),(h/2)),
            2,material));
}

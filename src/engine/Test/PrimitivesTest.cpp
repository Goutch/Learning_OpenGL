//
// Created by User on 02-Feb.-2020.
//

#include "PrimitivesTest.h"
#include <Core/Rendering/Renderer.h>
#include <Core/Viewport.h>
void PrimitivesTest::render() const {
    Scene::render();
    float w=viewport->getPixelWidth();
    float h=viewport->getPixelHeight();
    renderer->drawRect(100, 100, 100, 100, Color::RED);
    renderer->drawLine(0 ,0,w ,h, 1, Color::GREEN);
    renderer->drawLine(w ,0,0 ,h, 1, Color::WHITE);
    renderer->drawEllipse(w/2,h/2, 200, 200, Color::BLUE);
}

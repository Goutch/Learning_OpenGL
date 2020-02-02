//
// Created by User on 02-Feb.-2020.
//

#include "PrimitivesTest.h"
#include <Core/Rendering/Renderer.h>
void PrimitivesTest::render() const {
    Scene::render();
    renderer->drawRect(0,0,1,1,Color::RED);
    renderer->drawEllipse(0,0,1,1,Color::BLUE);
    renderer->drawLine(-1,-1,1,1,0.1,Color::GREEN);
}

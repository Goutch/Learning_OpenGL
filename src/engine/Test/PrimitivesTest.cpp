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

    renderer->drawEllipse(w/2,w/3, 500, 500, Color(1,1,0));

    renderer->drawLine((w/2)-50 ,((h/3)*2)+50,(w/2)-150 ,((h/3)*2)+30, 10, Color::BLACK);
    renderer->drawEllipse((w/2)-100,(h/3)*2, 40,20, Color::BLACK);

    renderer->drawLine((w/2)+50 ,((h/3)*2)+50,(w/2)+150 ,((h/3)*2)+30, 10, Color::BLACK);
    renderer->drawEllipse((w/2)+100,(h/3)*2, 40,20, Color::BLACK);

    renderer->drawRect(w/2, h/2, 30, 30, Color::BLACK);

    renderer->drawEllipse(w/2 ,150,70 ,70, Color::BLACK);


}

//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>
#include <Geometry/Geometry.h>
#include "TextTest.h"
#include <Entities/Spacial/MeshRenderer.h>
#include <Core/Window.h>
#include <Entities/Spacial/Camera.h>
#include <Core/Canvas.h>
#include <Entities/Canvas/Text.h>

void TextTest::init(const Canvas &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
    CanvasEntity* e= new Text("test", vec3(viewport.getPixelWidth() / 2, viewport.getPixelHeight() / 2, 0), font, 100);
    addEntity(e);
}
void TextTest::render() const {
    Scene::render();
}

//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>
#include <Geometry/Geometry.h>
#include "TextTest.h"
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>
#include <Entities/Camera.h>
#include <Core/Viewport.h>
#include <Entities/Text.h>

void TextTest::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
    Entity* e= new Text("test", vec3(viewport.getPixelWidth() / 2, viewport.getPixelHeight() / 2, 0), font, 100);
    addEntity(e);
}
void TextTest::render() const {
    Scene::render();
}

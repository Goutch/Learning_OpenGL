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
void TextTest::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
    camera->setProjectionMode(Camera::ProjectionMode::ORTHOGRAPHIC_UNITS);
    Geometry::make_text(vao, "test", font);
}
void TextTest::render() const {
    Scene::render();
    renderer->draw(vao, font, transform);
}

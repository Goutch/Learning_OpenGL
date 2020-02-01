//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>
#include <Geometry/Geometry.h>
#include "LAB2.h"
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>
#include <Entities/Camera.h>
#include <Core/Viewport.h>
void LAB2::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
    camera->setProjectionMode(Camera::ProjectionMode::ORTHOGRAPHIC_UNITS);
    Geometry::make_quad(vao);
    window.subscribeKeyPress(*this);
    float uvs[8];
    font.getCoordinates(uvs,'!'-32);
    vao.uvs(uvs, 8);
}
void LAB2::render() const {
    Scene::render();
    renderer->draw(vao, material, transform);
}


void LAB2::onKeyPress(char key) {
    float uvs[8];
    font.getCoordinates(uvs,key-32);
    vao.uvs(uvs, 8);
}

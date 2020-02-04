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
    Geometry::make_quad(vao);
    window.subscribeKeyPress(*this);
    float uvs[8];
    font.getCoordinates(uvs,'!'-32);
    vao.uvs(uvs, 8);
    transform.scale(vec3(300,300,1));
    transform.position(vec3(100,100,1));
}
void TextTest::render() const {
    renderer->drawUI(vao, transform, font);
    Scene::render();
}


void TextTest::onKeyPress(char key) {
    float uvs[8];
    font.getCoordinates(uvs,key-32);
    vao.uvs(uvs, 8);
}

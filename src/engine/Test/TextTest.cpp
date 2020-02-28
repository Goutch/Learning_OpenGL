//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>

#include "TextTest.h"
#include <Entities/Spacial/MeshRenderer.h>
#include <Core/Window.h>

#include <Core/Canvas.h>
#include <Entities/Canvas/Text.h>

void TextTest::init(const Canvas &viewport, Renderer &renderer, Input &input) {
    Scene::init(viewport, renderer, input);
    addEntity( new Text("test", glm::vec2(viewport.getPixelWidth() / 2, viewport.getPixelHeight() / 2), font, 64));
}


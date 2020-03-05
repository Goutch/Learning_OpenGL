//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>

#include "BaseScene.h"
#include <Entities/Spacial/MeshRenderer.h>
#include <Core/Window.h>

#include <Core/Canvas.h>
#include <Entities/Canvas/Text.h>

void BaseScene::init(const Canvas &viewport, Renderer &renderer, Input &input) {
    SpacialScene::init(viewport, renderer, input);
}

void BaseScene::draw() const {
    SpacialScene::draw();
}


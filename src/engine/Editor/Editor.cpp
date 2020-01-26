//
// Created by le6mon on 2020-01-26.
//

#include "Editor.h"
#include "Entities/MeshRenderer.h"
#include "Geometry/Geometry.h"
#include "Core/Renderer.h"
#include "Core/Window.h"

void Editor::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    currentScene->init(window, renderer);
}

void Editor::update(float delta) {
    Scene::update(delta);
    currentScene->update(delta);
}

void Editor::render() const {
    Scene::render();
    currentScene->render();
}

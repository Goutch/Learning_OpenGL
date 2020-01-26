//
// Created by User on 2020-01-26.
//

#include "Editor.h"

void Editor::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
}

void Editor::update(float delta) {
    Scene::update(delta);
}

void Editor::render() const {
    Scene::render();
}


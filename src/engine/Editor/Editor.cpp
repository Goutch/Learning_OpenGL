//
// Created by User on 2020-01-26.
//

#include "Editor.h"

void Editor::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
}

void Editor::update(float delta) {
    Scene::update(delta);
}

void Editor::render() const {
    Scene::render();
}



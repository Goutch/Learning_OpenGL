//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Camera.h>
#include <Entities/MeshRenderer.h>

Editor::Editor(Scene &scene) {
    this->current_scene = &scene;
}

Editor::~Editor() {
    delete current_scene_viewport;
}

void Editor::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);

    current_scene_viewport = new Viewport(viewport, 0.5, 0.5, 0, 0.5);
    current_scene->init(*current_scene_viewport, renderer, window);

    screen_mat.shader(current_scene_viewport->getShader());
    screen_mat.texture(current_scene_viewport->getFrameBuffer().getTexture());

    camera->setProjectionMode(Camera::ORTHOGRAPHIC_UNITS);
    addEntity(new MeshRenderer(current_scene_viewport->getRenderSpace(), screen_mat));
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}

void Editor::prepareRender() const {
    current_scene->prepareRender();
    current_scene->render();
    Scene::prepareRender();
}




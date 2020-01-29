//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Renderer.h>
#include <Entities/Camera.h>
#include <Entities/MeshRenderer.h>
Editor::Editor(Scene &scene) {
    this->current_scene=&scene;
}

Editor::~Editor() {
     delete current_scene_viewport;
}

void Editor::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
    camera->setProjectionMode(Camera::ORTHOGRAPHIC_UNITS);
    current_scene_viewport=new Viewport(viewport,1,1,0,0);
    current_scene->init(*current_scene_viewport,renderer,window);
    screen_mat.texture(current_scene_viewport->getFrameBuffer().getTexture());
    Geometry::make_quad(scene_screen,2,2);
    addEntity(new MeshRenderer(scene_screen,screen_mat));
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}
#include <Core/Window.h>
void Editor::render() const {
    renderer->render(viewport->getFrameBuffer(),*this,camera->getCameraSpaceMatrix());
}


void Editor::prepareRender() const {

    current_scene->prepareRender();
    current_scene->render();

    Scene::prepareRender();
}




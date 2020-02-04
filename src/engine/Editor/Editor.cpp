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
    viewport_mat=renderer.DEFAULT_MATERIAL;
    viewport_mat.texture(viewport.getFrameBuffer().getTexture());
    viewport_transform.position(vec3(100,100,0));
    viewport_transform.scale(vec3(viewport.getPixelWidth(),viewport.getPixelHeight(),1));
    current_scene_viewport = new Viewport(viewport, 1, 1, 0, 0);
    current_scene->init(*current_scene_viewport, renderer, window);
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}

void Editor::draw() const {
    //draw scene into scene buffer
    current_scene->draw();
    current_scene->render();
    //if Need to update
    if(true);
    {
        Scene::draw();
    }
}

void Editor::render() const {
    Scene::render();
    //draw current scene viewport in editor buffer
    renderer->drawUI(renderer->QUAD,viewport_transform,viewport_mat);
}




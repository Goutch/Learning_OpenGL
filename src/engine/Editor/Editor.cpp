//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Spacial/Camera.h>
#include <Entities/Spacial/MeshRenderer.h>

Editor::Editor(Scene &scene) {
    this->current_scene = &scene;
}

Editor::~Editor() {
    delete current_scene_canvas;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    current_scene_canvas_material=renderer.DEFAULT_CANVAS_MATERIAL;
    current_scene_canvas_material.setTexture(canvas.getFrameBuffer().getTexture());
    current_scene_canvas_transform.position(vec3(100, 100, 0));
    current_scene_canvas_transform.scale(vec3(canvas.getPixelWidth(), canvas.getPixelHeight(), 1));
    current_scene_canvas = new Canvas(canvas,renderer.DEFAULT_CANVAS_SHADER,500,500,0.0f,0.0f);
    current_scene->init(*current_scene_canvas, renderer, window);
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
    //draw current scene canvas in editor buffer
    renderer->draw(renderer->QUAD_CENTER, current_scene_canvas_transform, current_scene_canvas_material);
}




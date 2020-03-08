//
// Created by User on 2020-01-06.
//
#include "Core/Rendering/Renderer.h"
#include "Scene.h"
#include "Input.h"

#include "Core/Window.h"

#include "Utils/TimeUtils.h"
#include "Core/Canvas.h"
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
Scene::Scene() {

}

void Scene::update(float delta) {
    if (input->isKeyDown(GLFW_KEY_F11)) {
        canvas->getFrameBuffer().save("../screenshot/" + TimeUtils::getTimeString() + ".png");
    }
}

void Scene::draw() const {
    for (auto e:canvasEntities) {
        e->draw(*this);
    }
    renderer->clear();
}

void Scene::render() const{
    renderer->renderCanvas(canvas->getFrameBuffer(), canvas->getPixelProjection());
}

void Scene::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    this->renderer = &renderer;
    this->canvas = &canvas;
    this->input = &input;
}

const Canvas &Scene::getCanvas() const {
    return *canvas;
}

void Scene::addEntity(CanvasEntity *entity) {
    canvasEntities.push_back(entity);
    entity->init(*this);
}
Renderer &Scene::getRenderer() const {
    return *renderer;
}

Input &Scene::getInput() const {
    return *input;
}

Scene::~Scene() {
    for (unsigned int i = 0; i < canvasEntities.size(); ++i) {
        canvasEntities[i]->onDestroy(*this);
        delete canvasEntities[i];
    }
    canvasEntities.clear();
}














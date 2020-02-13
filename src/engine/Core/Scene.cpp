//
// Created by User on 2020-01-06.
//
#include "Scene.h"

#include "Core/Rendering/Renderer.h"
#include "Core/Window.h"

#include "Utils/TimeUtils.h"
#include "Core/Canvas.h"

Scene::Scene() {

}

void Scene::update(float delta) {
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->close();
    }
    if (window->isKeyDown(GLFW_KEY_F11)) {
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

void Scene::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    this->renderer = &renderer;
    this->canvas = &canvas;
    this->window = &window;
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

void Scene::destroy() {
    for (unsigned int i = 0; i < canvasEntities.size(); ++i) {
        canvasEntities[i]->onDestroy(*this);
        delete canvasEntities[i];
    }
    canvasEntities.clear();
}

Window &Scene::getWindow() const {
    return *window;
}














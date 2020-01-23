//
// Created by User on 2020-01-06.
//
#include "Scene.h"
#include "../Entities/Entity.h"
#include "Core/Renderer.h"
#include "Core/Window.h"
#include "Entities/Light/PointLight.h"

Scene::Scene() {

}

void Scene::update(float delta) {
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->close();
    }
    if (window->isKeyDown(GLFW_KEY_F11)) {
        renderer->screenshot();
    }
    for(auto e:entities){
        e->update(delta,*this);
    }
}

void Scene::render() {
    for(auto e:entities){
        e->render(*this);
    }
}

void Scene::init(Window &window, Renderer &renderer) {
    this->renderer=&renderer;
    this->window=&window;
    renderer.setCamera(camera);
}

void Scene::addEntity(Entity& entity)
{
    entities.push_back(&entity);
    entity.init(*this);
}

void Scene::addEntity(Entity *entity) {
    entities.push_back(entity);
    entity->init(*this);
}
Window &Scene::getWindow() {
    return *window;
}
Renderer &Scene::getRenderer() {
    return *renderer;
}
Scene::~Scene() {
    for (int i = 0; i < entities.size(); ++i) {
        delete entities[i];
    }

    for (int i = 0; i < point_lights.size(); ++i) {
        delete point_lights[i];
    }
    point_lights.clear();
    entities.clear();
}

void Scene::addLight(PointLight *light) {
    point_lights.push_back(light);
}

const std::vector<PointLight *> &Scene::getPointLights() const {
    return point_lights;
}

const Color &Scene::getAmbientLight() const {
    return ambient_light;
}

const Transform &Scene::getCamera() const{
    return camera;
}




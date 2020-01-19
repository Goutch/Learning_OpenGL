//
// Created by User on 2020-01-06.
//
#include "Scene.h"
#include "../Entities/Entity.h"
#include "Core/Renderer.h"
Scene::Scene() {

}

void Scene::update(float delta) {
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

unsigned int Scene::addEntity(Entity& entity)
{
    entities.push_back(&entity);
    entity.init(*this);
}

unsigned int Scene::addEntity(Entity *entity) {
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
    delete[] entities.data();
    entities.clear();
}




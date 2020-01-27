//
// Created by User on 2020-01-06.
//
#include "Scene.h"
#include "Entities/Entity.h"
#include "Core/Renderer.h"
#include "Core/Window.h"
#include "Entities/Light/PointLight.h"
#include "Data/FBO.h"
#include "Entities/Light/DirectionnalLight.h"
#include "Utils/TimeUtils.h"
#include "Entities/Camera.h"
#include "Core/Viewport.h"
Scene::Scene() {

}

void Scene::update(float delta) {
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->close();
    }
    if (window->isKeyDown(GLFW_KEY_F11)) {
        frame_buffer.save("../screenshot/" + TimeUtils::getTimeString() + ".png");
    }
    for(auto e:entities){
        e->update(delta,*this);
    }
    for (unsigned int i = 0; i < directional_lights.size(); ++i) {
        directional_lights[i]->calculateShadowMap(*this);
    }
}

void Scene::render() const {
    for(auto e:entities){
        e->render(*this);
    }
}


void Scene::init(Viewport &viewport, Renderer &renderer, Window &window) {
    frame_buffer.setSize(viewport.getWidth(),viewport.getHeight());

    this->renderer=&renderer;
    this->viewport=&viewport;
    this->window=&window;
    this->camera=new Camera(Camera::PERSPECTIVE);
    addEntity(this->camera);
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
const Viewport &Scene::getViewport() const{
    return *viewport;
}
Renderer &Scene::getRenderer()const {
    return *renderer;
}
Scene::~Scene() {
    for (unsigned int i = 0; i < entities.size(); ++i) {
        delete entities[i];
    }
    directional_lights.clear();
    point_lights.clear();
    entities.clear();
}

void Scene::addLight(PointLight *light) {
    point_lights.push_back(light);
    entities.push_back(light);
}

const std::vector<PointLight *> &Scene::getPointLights() const {
    return point_lights;
}

const Color &Scene::getAmbientLight() const {
    return ambient_light;
}

const Camera &Scene::getCamera() const{
    return *camera;
}

void Scene::addLight(DirectionalLight *light) {
    directional_lights.push_back(light);
    entities.push_back(light);
}
const std::vector<DirectionalLight*>& Scene::getDirectionalLights() const{
    return directional_lights;
}

const FBO &Scene::getFBO() const {
    return frame_buffer;
}

Window& Scene::getWindow() const {
    return *window;
}







//
// Created by User on 05-Feb.-2020.
//
#include <Core/Rendering/Renderer.h>
#include "SpacialScene.h"
#include "Entities/Spacial/Light/PointLight.h"
#include "Entities/Spacial/Light/DirectionnalLight.h"
#include "Entities/Spacial/Camera.h"

#include <Core/Canvas.h>
void SpacialScene::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    camera=new Camera();
    addEntity(camera);
}
void SpacialScene::update(float delta) {
    Scene::update(delta);
    for (auto e:spacialEntities) {
        e->update(delta, *this);
    }
    for (unsigned int i = 0; i < directional_lights.size(); ++i) {
        directional_lights[i]->calculateShadowMap(*this);
    }
}
void SpacialScene::draw() const {
    for (auto e:spacialEntities) {
        e->draw(*this);
    }
    Scene::draw();
}

void SpacialScene::addEntity(SpacialEntity *entity) {
    spacialEntities.push_back(entity);
    entity->init(*this);
}
void SpacialScene::render() const {
    renderer->renderSpace(canvas->getFrameBuffer(), camera->getProjectionMatrix(), camera->getViewMatrix());
    Scene::render();
}

void SpacialScene::addLight(PointLight *light) {
    point_lights.push_back(light);
    spacialEntities.push_back(light);
}

const std::vector<PointLight *> &SpacialScene::getPointLights() const {
    return point_lights;
}

const Color &SpacialScene::getAmbientLight() const {
    return ambient_light;
}
 Camera &SpacialScene::getCamera(){
    return *camera;
}

void SpacialScene::addLight(DirectionalLight *light) {
    directional_lights.push_back(light);
    spacialEntities.push_back(light);
}

const std::vector<DirectionalLight *> &SpacialScene::getDirectionalLights() const {
    return directional_lights;
}

SpacialScene::~SpacialScene() {
    for (unsigned int i = 0; i < spacialEntities.size(); ++i) {
        spacialEntities[i]->onDestroy(*this);
        delete spacialEntities[i];
    }
    spacialEntities.clear();
    directional_lights.clear();
    point_lights.clear();
}

const std::vector<SpacialEntity *> &SpacialScene::getSpacialEntities() const {
    return spacialEntities;
}

void SpacialScene::setCamera(Camera& camera) {
    this->camera=&camera;
}







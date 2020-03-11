//
// Created by User on 2020-01-18.
//

#include "DirectionnalLight.h"
#include "Core/Rendering/FBO.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Core/Scene.h"
#include "Entities/Camera.h"
std::set<const DirectionalLight*> DirectionalLight::instances;
void DirectionalLight::init(Scene &scene) {
    Entity::init(scene);
    instances.insert(this);
}

DirectionalLight::DirectionalLight(const Color &color, vec3 position, vec3 rotation) : Light(color, position,
                                                                                             rotation) {
    fbo = new FBO(quality, quality, FBO::DEPTH);
}

DirectionalLight::DirectionalLight(vec3 position, vec3 rotation) : Light(color, position, rotation) {
    fbo = new FBO(quality, quality, FBO::DEPTH);
}

DirectionalLight::DirectionalLight() : Light() {
    fbo = new FBO(quality,quality, FBO::DEPTH);
}

const Texture &DirectionalLight::getShadowMap() const {
    return fbo->getTexture();
}

void DirectionalLight::calculateShadowMap(const Scene &scene) {
    light_space_mat = depth_projection * glm::inverse(this->transform.getMatrix());
    scene.draw();
    scene.getRenderer().renderDepth(*fbo, light_space_mat);
}

const mat4 &DirectionalLight::getLightSpaceMat() const{
    return light_space_mat;
}

DirectionalLight::~DirectionalLight() {
    delete fbo;
}

void DirectionalLight::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    instances.erase(this);
}

const std::set<const DirectionalLight *> &DirectionalLight::getInstances() {
    return instances;
}
void DirectionalLight::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
    this->transform.position(scene.getCamera().transform.position());
    calculateShadowMap(scene);
}

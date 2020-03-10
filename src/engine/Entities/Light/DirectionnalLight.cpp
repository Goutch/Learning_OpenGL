//
// Created by User on 2020-01-18.
//

#include "DirectionnalLight.h"
#include "Core/Rendering/FBO.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Core/Scene.h"
#include "Entities/Camera.h"

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

const Texture &DirectionalLight::shadowMap() {
    return fbo->getTexture();
}

void DirectionalLight::calculateShadowMap(Scene &scene) {
    this->transform.position(scene.getCamera().transform.position());
    light_space_mat = depth_projection * glm::inverse(this->transform.getMatrix());
    scene.draw();
    scene.getRenderer().renderDepth(*fbo, light_space_mat);
}

const mat4 &DirectionalLight::getLightSpaceMat() {
    return light_space_mat;
}

DirectionalLight::~DirectionalLight() {
    delete fbo;
}

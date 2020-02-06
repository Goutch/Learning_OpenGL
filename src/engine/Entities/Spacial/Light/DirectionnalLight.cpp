//
// Created by User on 2020-01-18.
//

#include "DirectionnalLight.h"
#include "Data/FBO.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Core/SpacialScene.h"
#include "Entities/Spacial/Camera.h"

DirectionalLight::DirectionalLight(const Color &color, vec3 position, vec3 rotation) : Light(color, position,
                                                                                             rotation) {
    fbo = new FBO(2048, 2048, FBO::DEPTH);
}

DirectionalLight::DirectionalLight(vec3 position, vec3 rotation) : Light(color, position, rotation) {
    fbo = new FBO(2048, 2048, FBO::DEPTH);
}

DirectionalLight::DirectionalLight() : Light() {
    fbo = new FBO(2048, 2048, FBO::DEPTH);
}

const Texture &DirectionalLight::shadowMap() {
    return fbo->getTexture();
}


void DirectionalLight::calculateShadowMap(SpacialScene &scene) {
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

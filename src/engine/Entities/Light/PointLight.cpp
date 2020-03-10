//
// Created by User on 2020-01-19.
//

#include "PointLight.h"

std::set<const PointLight*> PointLight::instances;
void PointLight::init(Scene &scene) {
    Entity::init(scene);
    instances.insert(this);
}
PointLight::PointLight(const Color &color, float radius, vec3 position) : Light(color, position) {
    this->radius = radius;
}

PointLight::PointLight(float radius, vec3 position) : Light(position) {
    this->radius = radius;
}

PointLight::PointLight(const Color &color, vec3 position) : Light(color, position) {
}

PointLight::PointLight(vec3 position) : Light(position) {
}

PointLight::PointLight() : Light() {

}

float PointLight::getRadius()const {
    return radius;
}

void PointLight::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    instances.erase(this);
}

const std::set<const PointLight *>& PointLight::getInstances() {
    return instances;
}





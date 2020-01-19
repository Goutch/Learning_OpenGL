//
// Created by User on 2020-01-19.
//

#include "PointLight.h"

PointLight::PointLight(const Color &color, float radius, vec3 position) : Light(position) {
    this->radius = radius;
}

PointLight::PointLight(float radius, vec3 position) : Light(position) {
    this->radius = radius;
}

PointLight::PointLight(const Color &color, vec3 position) : Light(position) {
    this->color = color;
}

PointLight::PointLight(vec3 position) : Light(position) {
}

PointLight::PointLight() : Light() {

}

float PointLight::getRadius() {
    return radius;
}



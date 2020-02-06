//
// Created by User on 2020-01-18.
//

#include "Light.h"
Light::Light(const Color&color, vec3 position, vec3 rotation, vec3 scale) : SpacialEntity(position, rotation, scale) {
    this->color=color;
}

Light::Light(vec3 position, vec3 rotation, vec3 scale) : SpacialEntity(position, rotation, scale) {

}

Light::Light(const Color& color) : SpacialEntity() {
    this->color=color;
}

Light::Light() : SpacialEntity() {

}

const Color &Light::getColor() {
    return color;
}

//
// Created by User on 05-Feb.-2020.
//

#include "CanvasTransform.h"

CanvasTransform::CanvasTransform() {

}

CanvasTransform::CanvasTransform(vec2 position, float rotation, vec2 scale) {
    this->translate(position);
    this->rotate(rotation);
    this->scale(scale);
}

void CanvasTransform::position(vec2 position) {
    transform_matrix[3] = vec4(position,0, transform_matrix[3].w);
}

void CanvasTransform::translate(vec2 translation) {
    transform_matrix = glm::translate(transform_matrix, vec3(translation,0));
}

vec2 CanvasTransform::position() const {
    return parent == nullptr ?transform_matrix[3]: parent->position() + (vec2)transform_matrix[3];
}

void CanvasTransform::scale(vec2 scale) {
    transform_matrix[0] = normalize(transform_matrix[0]) * scale.x;
    transform_matrix[1] = normalize(transform_matrix[1]) * scale.y;
}

vec2 CanvasTransform::scale() const{
    vec2 s;
    s.x = glm::length(transform_matrix[0]);
    s.y = glm::length(transform_matrix[1]);
    return s;

}

void CanvasTransform::rotate(float rotation) {
    rot+=rotation;
    transform_matrix=glm::rotate(transform_matrix,rotation,vec3(0,0,1));
}

float CanvasTransform::rotation() const{
    return rot;
}

mat4 CanvasTransform::getMatrix()const {
    return transform_matrix;
}

CanvasTransform::CanvasTransform(const CanvasTransform &other) {
    this->transform_matrix=other.transform_matrix;
    this->rot=other.rot;
    this->parent=other.parent;
}

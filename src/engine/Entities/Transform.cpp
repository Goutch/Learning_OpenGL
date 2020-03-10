//
// Created by User on 2020-01-02.
//

#include "Transform.h"

Transform::Transform() {

}

Transform::Transform(vec3 position, vec3 rotation, vec3 scale) {
    this->translate(position);
    this->rotate(quat(rotation));
    this->scale(scale);
}

mat4 Transform::getMatrix() const {
    return parent == nullptr ? transform_matrix : parent->getMatrix() * transform_matrix;
}


void Transform::translate(const vec3 &translation) {
    transform_matrix = glm::translate(transform_matrix, translation);
}

void Transform::rotate(const quat &rotation) {
    rot *= rotation;
    mat4 rot_matrix = glm::toMat4(rotation);
    transform_matrix = transform_matrix * rot_matrix;
}

void Transform::rotate(float angle, vec3 axis) {
    rot = glm::rotate(rot, angle, axis);
    transform_matrix = glm::rotate(transform_matrix, angle, axis);
}

vec3 Transform::forward() {
    return glm::normalize(transform_matrix[2]);
}

vec3 Transform::right() {
    return glm::normalize(transform_matrix[0]);
}

vec3 Transform::up() {
    return glm::normalize(transform_matrix[1]);
}

quat Transform::rotation() const {
    return parent == nullptr ?rot: rot * parent->rotation();
}
void Transform::rotation(const quat &rotation) {
    rot=glm::identity<quat>();
    vec3 p=position();
    vec3 s=scale();
    transform_matrix=mat4(1.0f);
    this->translate(p);
    this->rotate(rotation);
    this->scale(s);
}

vec3 Transform::position() const {
    return parent == nullptr ?transform_matrix[3]: (vec3)(parent->getMatrix()*transform_matrix)[3];
}

vec3 Transform::localPosition() const {
    return transform_matrix[3];
}

vec3 Transform::scale() const{
    vec3 s;
    s.x = glm::length(transform_matrix[0]);
    s.y = glm::length(transform_matrix[1]);
    s.z = glm::length(transform_matrix[2]);
    return s;
}

void Transform::position(const vec3 &position) {
    transform_matrix[3].x= position.x;
    transform_matrix[3].y=position.y;
    transform_matrix[3].z=position.z;
}

void Transform::scale(vec3 scale) {
    transform_matrix[0] = normalize(transform_matrix[0]) * scale.x;
    transform_matrix[1] = normalize(transform_matrix[1]) * scale.y;
    transform_matrix[2] = normalize(transform_matrix[2]) * scale.z;
}

vec3 Transform::eulerRotation() const {

    return glm::eulerAngles(rot);
}















//
// Created by User on 19-Nov.-2019.
//

#include "Transform.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>

Transform::Transform() {

}

Transform::Transform(glm::vec3 position, glm::quat rotation, glm::vec3 scale,Transform* parent) {
    setParent(parent);
    localPosition(position);
    localRotation(rotation);
    localScale(scale);
}

glm::mat4 Transform::toMatrix() {
    return transform_mattrix;
}
void Transform::setParent(Transform* parent) {
    this->parent=parent;
}
void Transform::translate(glm::vec3 translation) {
    transform_mattrix = glm::translate(transform_mattrix, translation);
}

void Transform::rotate(glm::vec3 axis, float angle) {
    transform_mattrix = glm::rotate(transform_mattrix, angle, axis);
}

void Transform::scale(glm::vec3 scale) {
    transform_mattrix = glm::scale(transform_mattrix, scale);
}

glm::vec3 Transform::localPosition() {
    return local_pos;
}

glm::quat Transform::localRotation() {
    return local_rot;
}

glm::vec3 Transform::localScale() {
    return local_scale;
}

glm::vec3 Transform::globalPosition() {
    return glm::vec3();
}

glm::quat Transform::globalRotation() {
    return glm::quat();
}

glm::vec3 Transform::globalScale() {
    return glm::vec3();
}

void Transform::localPosition(glm::vec3 position) {

}

void Transform::localRotation(glm::quat rotation) {

}

void Transform::localScale(glm::vec3 scale) {

}

void Transform::globalPosition(glm::vec3 position) {

}

void Transform::globalRotation(glm::quat rotation) {

}

void Transform::globalScale(glm::vec3 scale) {

}



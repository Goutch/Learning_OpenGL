//
// Created by User on 19-Nov.-2019.
//

#include "Transform.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
Transform::Transform() {

}

glm::mat4 Transform::toMatrix() {
    return transform_mattrix;
}

void Transform::translate(glm::vec3 translation) {
    transform_mattrix=glm::translate(transform_mattrix, translation);
}

void Transform::rotate(glm::vec3 axis,float angle) {
    transform_mattrix=glm::rotate(transform_mattrix,angle,axis);
}
void Transform::scale(glm::vec3 scale) {
    transform_mattrix=glm::scale(transform_mattrix,scale);
}

Transform::Transform(glm::vec3 position) {
    translate(position);
}

glm::vec3 Transform::position() {
    return glm::vec3(transform_mattrix[3]);
}

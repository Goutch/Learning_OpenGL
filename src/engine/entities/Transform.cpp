//
// Created by User on 19-Nov.-2019.
//

#include "Transform.h"
#include <glm/gtx/transform.hpp>
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

//
// Created by User on 19-Nov.-2019.
//

#include "Transform.h"
#include <glm/gtx/transform.hpp>
Transform::Transform() {

}

glm::mat4x4 Transform::getTransformMattrix() {
    return transform_mattrix;
}

void Transform::translate(glm::vec3 pos) {
    glm::translate(transform_mattrix, pos);
}

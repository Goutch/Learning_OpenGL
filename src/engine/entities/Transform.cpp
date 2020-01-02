//
// Created by User on 2020-01-02.
//

#include "Transform.h"

Transform::Transform() {

}
mat4 Transform::getMatrix() {
    return transform_matrix;
}

void Transform::translate(const vec3 &translation) {
    pos+=translation;
    transform_matrix.translate(translation);
}

void Transform::rotate(const vec3 &rotation) {
    rot+=rotation;
    transform_matrix.rotate(rotation);
}



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
    transform_matrix=glm::translate(transform_matrix,translation);
    //transform_matrix.translate(translation);
}

void Transform::rotate(float angle,const vec3& axis) {
    transform_matrix=glm::rotate(transform_matrix,angle,axis);
   // transform_matrix.rotate(angle,axis);
}



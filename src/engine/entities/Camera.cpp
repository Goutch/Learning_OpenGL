//
// Created by User on 10-Dec.-2019.
//

#include "Camera.h"
mat4 Camera::getViewMatrix() {
    return mat4(getMatrix()).inverse();
}

Camera::Camera(vec3 position):Transform() {
    translate(position);
}

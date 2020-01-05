//
// Created by User on 10-Dec.-2019.
//

#include "Camera.h"
#include "iostream"
mat4 Camera::getViewMatrix() {
    return getMatrix().inverse();
}

Camera::Camera(vec3 position):Transform() {
    translate(position);
}

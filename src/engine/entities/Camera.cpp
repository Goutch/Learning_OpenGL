//
// Created by User on 10-Dec.-2019.
//

#include "Camera.h"

glm::mat4 Camera::getViewMatrix() {
    return inverse(toMatrix());
}

Camera::Camera(glm::vec3 position):Transform() {
    translate(position);
}

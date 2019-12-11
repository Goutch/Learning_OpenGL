#pragma once
#include "Entity.h"

class Camera :public Transform {
public:
    Camera(glm::vec3 position);
    glm::mat4  getViewMatrix();

};

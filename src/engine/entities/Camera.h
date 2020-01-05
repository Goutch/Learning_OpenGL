#pragma once

#include "Transform.h"
class Camera :public Transform {
public:
    Camera(vec3 position);
    mat4  getViewMatrix();

};

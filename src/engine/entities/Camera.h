#pragma once
#include "Entity.h"

class Camera :public Transform {
public:
    Camera(vec3 position);
    mat4  getViewMatrix();

};

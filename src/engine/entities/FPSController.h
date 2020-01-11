#pragma once

#include "entities/Entity.h"

class FPSController: public Entity {
public:
    float aspect_ratio;
    float fov;
    FPSController(float aspectRatio,float fov,vec3 position,vec3 rotation,vec3 scale);
    void update(float delta, Scene& scene) override ;

};



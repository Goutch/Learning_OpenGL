#pragma once

#include "entities/Entity.h"

class FPSController: public Entity {
public:
    FPSController(vec3 position,vec3 rotation,vec3 scale);
    FPSController();
    void update(float delta, Scene& scene) override ;

};



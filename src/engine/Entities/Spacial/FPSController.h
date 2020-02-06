#pragma once

#include "SpacialEntity.h"

class FPSController: public SpacialEntity {
private:
    Transform* camera;
    float speed=100;
public:
    FPSController(Transform& camera,vec3 position,vec3 rotation,vec3 scale);
    FPSController(Transform& camera);


    void update(float delta, SpacialScene &scene) override ;

    void init(SpacialScene &scene) override;

};



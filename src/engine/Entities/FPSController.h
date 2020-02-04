#pragma once

#include "Entities/Entity.h"

class FPSController: public Entity {
private:
    Transform* camera;
    float speed=100;
public:
    FPSController(Transform& camera,vec3 position,vec3 rotation,vec3 scale);
    FPSController(Transform& camera);


    void update(float delta, Scene& scene) override ;

    void init(Scene &scene) override;

};



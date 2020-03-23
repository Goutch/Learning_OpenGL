#pragma once

#include "Entity.h"
#include "Camera.h"

class FPSController: public Entity {
private:
    Camera* camera;
    float speed=1000;
public:
    FPSController(Camera &camera, vec3 position, vec3 rotation, vec3 scale);
    FPSController(Camera &camera);


    void update(float delta, Scene &scene) override ;

    void init(Scene &scene) override;

};



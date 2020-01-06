#pragma once

#include "entities/Entity.h"
#include "entities/Transform.h"
class FPSController: public Entity {
public:
    float aspect_ratio;
    float fov;
    FPSController(float aspectRatio,float fov,vec3 position,vec3 rotation,vec3 scale);
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;

};



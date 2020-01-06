#pragma once

#include "entities/Entity.h"
class CameraController:Entity {
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;

};



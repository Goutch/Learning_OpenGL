
#pragma once

#include "Entities/Entity.h"
#include "Data/Color.h"
class Light:Entity {
    Color color=Color::WHITE;
public:
    Light(Color color,vec3 position,vec3 rotation,vec3 scale);
    Light(vec3 position,vec3 rotation,vec3 scale);
    Light(const Color& color);
    Light();
};

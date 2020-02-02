#pragma once

#include <Shaders/FontMaterial.h>
#include "Entity.h"

class Text : public Entity {
private:
    FontMaterial& font;
    Mesh mesh = Mesh();
public:
    Text(std::string text, const vec3 &position, FontMaterial &font);

    void render(const Scene &scene) const override;
};



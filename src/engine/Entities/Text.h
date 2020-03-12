#pragma once

#include <Ressources/Shaders/Material/FontMaterial.h>
#include "Entities/Entity.h"

#include "Ressources/Mesh.h"

class Text : public Entity{
private:
    std::string text;
    float size;
    FontMaterial* font;
    Mesh mesh = Mesh();
public:
    const std::string &getText() const;
    Text(std::string text, const glm::vec3 &position, FontMaterial &font, float size);
    void setText(std::string text);
    void draw(const Scene &scene) const override;
};



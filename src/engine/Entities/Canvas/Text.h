#pragma once

#include <Shaders/Canvas/FontMaterial.h>
#include "Entities/Spacial/SpacialEntity.h"
#include "CanvasEntity.h"
#include "Ressources/Mesh.h"

class Text : public CanvasEntity {
private:
    std::string text;
    float size;
    FontMaterial* font;
    Mesh mesh = Mesh();
public:
    const std::string &getText() const;
    Text(std::string text, const glm::vec2 &position, FontMaterial &font, float size);
    void setText(std::string text);
    void draw(const Scene &scene) const override;
};



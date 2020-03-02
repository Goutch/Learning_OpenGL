#pragma once

#include <Shaders/Canvas/FontMaterial.h>
#include "Entities/Spacial/SpacialEntity.h"
#include "CanvasEntity.h"
#include "Ressources/Mesh.h"

class Text : public CanvasEntity {
private:
    FontMaterial* font;
    Mesh mesh = Mesh();
public:
    Text(std::string text, const glm::vec2 &position, FontMaterial &font, float size);

    void draw(const Scene &scene) const override;
};



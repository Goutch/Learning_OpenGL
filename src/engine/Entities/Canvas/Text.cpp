

#include <Geometry/Geometry.h>
#include "Text.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

Text::Text(std::string text, const vec2 &position, FontMaterial &font, float size) : CanvasEntity(position){
    this->font=&font;
    Geometry::make_text(mesh, text, font);
    this->text= text;
    this->size = size;
    transform.scale(vec2(size,size));
}

void Text::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    scene.getRenderer().draw(mesh, transform, *font);
}

void Text::setText(std::string text) {
    Geometry::make_text(mesh, text, *this->font);
    transform.scale(vec2(size,size));
    this->text= text;
}

const std::string &Text::getText() const {
    return text;
}

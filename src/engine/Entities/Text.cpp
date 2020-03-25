

#include <Utils/Geometry.h>
#include "Text.h"
#include "Core/Scene.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

Text::Text(std::string text, const vec3 &position, FontMaterial &font, float size) : Entity(position){
    this->font=&font;
    Geometry::make_text(mesh, text, font);
    this->text= text;
    this->size = size;
    transform.setScale(vec3(size,size,0));

}

void Text::draw(const Scene &scene) const {
    Entity::draw(scene);
    scene.getRenderer().draw(mesh,*font,transform);
}

void Text::setText(std::string text) {
    Geometry::make_text(mesh, text, *this->font);
    transform.setScale(vec3(size,size,1));
    this->text= text;
}

const std::string &Text::getText() const {
    return text;
}

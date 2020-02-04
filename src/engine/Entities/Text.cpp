

#include <Geometry/Geometry.h>
#include "Text.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"


Text::Text(std::string text, const vec3 &position, FontMaterial &font, float size) : Entity(position){
    this->font=&font;
    Geometry::make_text(mesh, text, font);
    transform.scale(vec3(size,size,1));
}

void Text::draw(const Scene &scene) const {
    Entity::draw(scene);
    scene.getRenderer().drawUI(mesh, transform, *font);
}



#include <Geometry/Geometry.h>
#include "Text.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

Text::Text(std::string text, const vec3 &position, FontMaterial &font, float size) : CanvasEntity(){
    this->font=&font;
    Geometry::make_text(mesh, text, font);
    transform.scale(vec2(size,size));
}

void Text::draw(const Scene &scene) const {
    CanvasEntity::draw(scene);
    scene.getRenderer().draw(mesh, transform, *font);
}

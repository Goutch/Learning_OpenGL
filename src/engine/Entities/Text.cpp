//
// Created by le6mon on 2020-02-02.
//

#include <Geometry/Geometry.h>
#include "Text.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"

void Text::init(Scene &scene) {
    Entity::init(scene);
}

void Text::render(const Scene &scene) const {
    Entity::render(scene);
    scene.getRenderer().draw(mesh, font, transform);
}

void Text::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
}

void Text::destroy(Scene &scene) {
    Entity::destroy(scene);
}

Text::Text(std::string text, const vec3 &position, FontMaterial &font) : Entity(position, vec3(1), vec3(1)),
                                                                                                font(font) {
    Geometry::make_text(mesh, text, font);
}

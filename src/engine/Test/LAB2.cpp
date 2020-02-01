//
// Created by User on 21-Jan.-2020.
//

#include <Core/Rendering/Renderer.h>
#include <Geometry/Geometry.h>
#include "LAB2.h"
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>

#include <Core/Viewport.h>
void LAB2::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);

    Geometry::make_text(vao);
}

void LAB2::render() const {
    Scene::render();
    renderer->draw(vao, defaultMat);

}


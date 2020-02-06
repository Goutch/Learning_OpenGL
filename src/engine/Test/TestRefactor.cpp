//
// Created by User on 06-Feb.-2020.
//

#include <Core/Rendering/Renderer.h>
#include <Geometry/Geometry.h>
#include "TestRefactor.h"
#include <Entities/Spacial/MeshRenderer.h>
void TestRefactor::init(Canvas &canvas, Renderer &renderer, Window &window) {
    SpacialScene::init(canvas, renderer, window);
    Geometry::make_cube(vao);
    addEntity(new MeshRenderer(vao,renderer.DEFAULT_SPACIAL_MATERIAL,vec3(0,0,-4)));
    addEntity(new MeshRenderer(vao,renderer.DEFAULT_SPACIAL_MATERIAL,vec3(0,0,4)));
}

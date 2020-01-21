//
// Created by User on 21-Jan.-2020.
//

#include <Core/Renderer.h>
#include <Geometry/Geometry.h>
#include "LAB2.h"
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>
void LAB2::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    renderer.setRenderMode(window,Renderer::ORTHOGRAPHIC_PIXEL);
    Geometry::make_quad(quad);
    int width=2;
    int height=2;
    int size=100;
    int gap=25;
    for (int i = -width; i <=width ; ++i) {
        for (int j = -height; j <=height ; ++j) {
            addEntity(new MeshRenderer(quad,materials[((j+height)+(i+width))%2],vec3((float)j*(size+gap),(float)i*(size+gap),-1),vec3(0),vec3(size)));
        }
    }

}


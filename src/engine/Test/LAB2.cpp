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
    renderer.setRenderMode(window.getWidth(),window.getHeight(),Renderer::ORTHOGRAPHIC_PIXEL);
    Geometry::make_quad(quad);
    int width=4;
    int height=3;
    int size=100;
    int gap=25;

    
    for (int i = 1; i <= width+1 ; ++i) {
        for (int j = 1; j <= height+1 ; ++j) {
            addEntity(new MeshRenderer(quad,materials[(i + j) % 2],vec3((float)i*(size+gap),(float)j*(size+gap),-1),vec3(0),vec3(size)));
        }
    }

}


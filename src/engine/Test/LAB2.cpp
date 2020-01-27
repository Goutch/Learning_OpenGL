//
// Created by User on 21-Jan.-2020.
//

#include <Core/Renderer.h>
#include <Geometry/Geometry.h>
#include "LAB2.h"
#include <Entities/MeshRenderer.h>
#include <Core/Window.h>

void LAB2::init(Viewport &viewport, Renderer &renderer, Window &window){
    Scene::init(viewport,renderer,window);
    renderer.setRenderMode(window.getWidth(), window.getHeight(), Renderer::ORTHOGRAPHIC_PIXEL);
    Geometry::make_quad(quad);
    int width = 3;
    int height = 2;
    int size = 300;
    int gap = 25;


    for (int col = 0; col <= width; ++col) {
        for (int row = 0; row <= height; ++row) {
            float x = (float) (gap+(gap*col)+(size*col)+((float)size/2));
            float y =(float) (gap+(gap*row)+(size*row)+((float)size/2)) ;
            addEntity(new MeshRenderer(quad, materials[(col+row) % 3], vec3(x, y, -1), vec3(0), vec3(size)));
        }

    }

}


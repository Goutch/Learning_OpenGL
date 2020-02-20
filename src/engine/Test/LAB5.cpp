//
// Created by User on 20-Feb.-2020.
//

#include "LAB5.h"
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Spacial/FPSController.h>
#include <Entities/Spacial/Light/DirectionnalLight.h>
void LAB5::init(const Canvas &viewport, Renderer &renderer, Window &window) {
    SpacialScene::init(viewport, renderer, window);
    ambient_light=Color(0.1,0.1,0.1,1);
    dragon_material.shine(30);
    dragon_material.damp(16);
    cube_material.setColor(Color(.5,.7,.4,1));
    dragon_material.setColor(Color(0.7,0.4,0.4));
    Geometry::make_cube(cube_mesh);
    addEntity(new MeshRenderer(cube_mesh,cube_material,vec3(0),vec3(0),vec3(1000,1,1000)));
    addEntity(new MeshRenderer(dragon_mesh,dragon_material,vec3(0)));

    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(3,0.5,6),vec3(0),vec3(5,5,5)));
    addEntity(new FPSController(camera.transform));
    addLight(new DirectionalLight(Color(1,1,1,1),vec3(0),vec3(-3.1416/4,0,0)));
}

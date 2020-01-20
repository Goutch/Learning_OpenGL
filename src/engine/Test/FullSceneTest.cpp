//
// Created by User on 2020-01-18.
//

#include "FullSceneTest.h"
#include "Entities/MeshRenderer.h"
#include "Entities/FPSController.h"
#include "Entities/Light/PointLight.h"
void FullSceneTest::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    Geometry::make_plane(plane,10,10);
    Geometry::make_cube(cube);
    Geometry::make_sphere(sphere,10,10);

    dragon_material.shine(20);

    addEntity(new MeshRenderer(plane,ground_material,vec3(0),vec3(0),vec3(5)));
    addEntity(new MeshRenderer(cube,dragon_material,vec3(0,0.5,0),vec3(0),vec3(12,1,8)));
    addEntity(new MeshRenderer(dragon,dragon_material,vec3(0,.9,0)));
    addEntity(new MeshRenderer(cube,dragon_material,vec3(8,1,8)));
    addEntity(new MeshRenderer(sphere,dragon_material,vec3(-8,1,8)));
    addEntity(new FPSController(camera,vec3(0,1,10),vec3(0),vec3(1)));

    addLight(new PointLight(20,vec3(10,1,10)));
    addLight(new PointLight(20,vec3(-10,1,10)));
    addLight(new PointLight(20,vec3(10,1,-10)));
    addLight(new PointLight(20,vec3(-10,1,-10)));
}

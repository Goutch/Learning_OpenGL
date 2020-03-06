//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
#include "Grass.h"
void SpacialSceneDemo::init(const Canvas &viewport, Renderer &renderer, Input &input){
    SpacialScene::init(viewport, renderer, input);
    input.showCursor(false);
    //create cube_mesh mesh
    Geometry::make_cube(cube_mesh);
    Geometry::make_sphere(sphere_mesh,1,100,50);

    //ground
    addEntity(new MeshRenderer(cube_mesh, ground_material, vec3(0, -.5, 0), vec3(0), vec3(1000, 1, 1000)));
    addEntity(new Grass());
    //sphere
    addEntity(new MeshRenderer(sphere_mesh, sphere_material, vec3(0, 5, 0)));
    //bunnies
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(10,0,0)));
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(-10,0,0)));

    //dragons
    dragon_material.shine(20);
    dragon_material.damp(16);
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, 10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, -10)));
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, -10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, 10)));

    //controller
    addEntity(new FPSController(camera.transform, vec3(0, 2, 2), vec3(0), vec3(1)));

    //Directional sun light

    sun = new DirectionalLight(Color(1,1,1),vec3(0, 2, 0), glm::radians(vec3(-45, -45, 0)));

    addLight(sun);
}

void SpacialSceneDemo::update(float delta) {
    SpacialScene::update(delta);
}

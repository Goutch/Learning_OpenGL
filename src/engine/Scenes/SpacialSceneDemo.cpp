//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
void SpacialSceneDemo::init(const Canvas &viewport, Renderer &renderer, Input &input){
    SpacialScene::init(viewport, renderer, input);

    //create cube_mesh mesh
    Geometry::make_cube(cube_mesh);
    Geometry::make_sphere(sphere_mesh,1,100,50);

    //sphere
    addEntity(new MeshRenderer(sphere_mesh, sphere_material, vec3(0, 5, 0)));

    //ground
    addEntity(new MeshRenderer(cube_mesh, ground_material, vec3(0, -.5, 0), vec3(0), vec3(100, 1, 100)));

    //bunnies
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(10,0,0)));
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(-10,0,0)));

    //dragons
    dragon_material.shine(1);
    dragon_material.damp(6);
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, 10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, -10)));
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, -10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, 10)));

    //controller
    addEntity(new FPSController(camera.transform, vec3(0, 2, 2), vec3(0), vec3(1)));

    //middle point light
    addLight(new PointLight(Color(1, 0, 0), 10, vec3(0, 1, 0)));

    //Directional sun light
    MeshRenderer* sun_cube=new MeshRenderer(cube_mesh, cube_material, vec3(0, 0, 30), vec3(0), vec3(3));
    sun = new DirectionalLight(Color(1,1,1),vec3(0, 2, 0), glm::radians(vec3(-45, -45, 0)));
    cube_material.setColor(Color(1, 1, 0));
    addEntity(sun_cube);
    addLight(sun);
}

void SpacialSceneDemo::update(float delta) {
    SpacialScene::update(delta);
    sun->transform.rotate(quat(vec3(delta*0.01,0,0)));
}

//
// Created by User on 2020-01-18.
//

#include "FullSceneTest.h"
#include "Entities/MeshRenderer.h"
#include "Entities/FPSController.h"
#include "Entities/Light/PointLight.h"
#include "Entities/Light/DirectionnalLight.h"
#include "Entities/Camera.h"
void FullSceneTest::init(Viewport &viewport, Renderer &renderer, Window &window){
    Scene::init(viewport,renderer,window);

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
    //addEntity(new FPSController(camera->transform, vec3(0, 1, 2), vec3(0), vec3(1)));

    //middle point light
    addLight(new PointLight(Color(1, 0, 0), 10, vec3(0, 1, 0)));

    //Directional sun light
    MeshRenderer* sun_cube=new MeshRenderer(cube_mesh, cube_material, vec3(0, 0, 30), vec3(0), vec3(3));
    sun = new DirectionalLight(Color(1,1,1),vec3(0, 2, 0), glm::radians(vec3(-45, 0, 0)));
    cube_material.color(Color(1,1,0));
    addEntity(sun_cube);
    addLight(sun);
    sun_cube->transform.parent=&sun->transform;
}


void FullSceneTest::render() const {
    Scene::render();

}

void FullSceneTest::update(float delta) {
    Scene::update(delta);
    sun->transform.rotate(quat(vec3(delta*0.01,0,0)));
}

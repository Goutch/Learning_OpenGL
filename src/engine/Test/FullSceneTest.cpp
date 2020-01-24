//
// Created by User on 2020-01-18.
//

#include "FullSceneTest.h"
#include "Entities/MeshRenderer.h"
#include "Entities/FPSController.h"
#include "Entities/Light/PointLight.h"
#include "Entities/Light/DirectionnalLight.h"
void FullSceneTest::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);


    Geometry::make_cube(cube);

    dragon_material.shine(20);

    addEntity(new MeshRenderer(cube, ground_material, vec3(0), vec3(0), vec3(100,1,100)));
    addEntity(new MeshRenderer(cube, cube_material, vec3(0, 1.5, 0), vec3(0), vec3(3)));
    addEntity(new MeshRenderer(cube, dragon_material, vec3(0, 0.5, 10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon, dragon_material, vec3(0, .9, -10)));
    addEntity(new MeshRenderer(cube, dragon_material, vec3(0, 0.5, -10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon, dragon_material, vec3(0, .9, 10)));

    addEntity(new FPSController(camera, vec3(0, 1, 2), vec3(0), vec3(1)));
    addLight(new PointLight(Color(0, 1, 0), 20, vec3(0, 1, 0)));
    sun = new DirectionalLight(Color(0.8,0.6,0),vec3(0, 2, 0), glm::radians(vec3(-45, 0, 0)));
    addLight(sun);
    cube_material.texture(sun->shadowMap());
}


void FullSceneTest::render() const {
    Scene::render();

}

void FullSceneTest::update(float delta) {
    Scene::update(delta);
    sun->transform.rotate(quat(vec3(delta*0.1,0,0)));
}

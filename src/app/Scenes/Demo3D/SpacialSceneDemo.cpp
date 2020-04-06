//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
#include "Grass.h"
void SpacialSceneDemo::init(Canvas &canvas, Renderer &renderer, Input &input){
    Scene::init(canvas, renderer, input);
    canvas.setShader(edge_shader);
    ambient_light=Color(0.2,0.2,0.2,2);
    input.showCursor(false);
    //create cube_mesh mesh
    Geometry::make_cube(cube_mesh);
    Geometry::make_sphere(sphere_mesh,1,100,50);

    dragon_material.shine(30);
    dragon_material.damp(16);
    dragon_material.setColor(Color(0.7,0.4,0.4));
    //ground
    instantiate(new MeshRenderer(cube_mesh, ground_material, vec3(0, -.5, 0), vec3(0), vec3(1000, 1, 1000)));
    //sphere
    instantiate(new MeshRenderer(sphere_mesh, sphere_material, vec3(0, 5, 0)));
    //bunnies
    instantiate(new MeshRenderer(bunny_mesh, bunny_material, vec3(10, 0, 0)));
    instantiate(new MeshRenderer(bunny_mesh, bunny_material, vec3(-10, 0, 0)));
    auto P=new MeshRenderer(cube_mesh,player_material);
    P->setParent(camera);
    instantiate(P);
    //dragons
    dragon_material.shine(20);
    dragon_material.damp(16);
    instantiate(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, 10), vec3(0), vec3(12, 1, 8)));
    instantiate(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, -10)));
    instantiate(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, -10), vec3(0), vec3(12, 1, 8)));
    instantiate(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, 10)));

    //controller
    instantiate(new FPSController(*camera, vec3(0, 2, 2), vec3(0), vec3(1)));

    //Directional sun light

    sun = new DirectionalLight(Color(1,1,1),vec3(0, 2, 0), glm::radians(vec3(-45, -45, 0)));

    instantiate(sun);

}

void SpacialSceneDemo::update(float delta) {
    Scene::update(delta);
    if(input->isKeyDown(GLFW_KEY_1))
    {
        canvas->setShader(edge_shader);
    }
    if(input->isKeyDown(GLFW_KEY_0))
    {
        canvas->setShader(renderer->DEFAULT_2D_SHADER);
    }
    edge_shader.bind();
    edge_shader.loadUniform("resolution",vec2(canvas->getPixelWidth(),canvas->getPixelHeight()));
    edge_shader.unbind();

}

void SpacialSceneDemo::render() const {
    Scene::render();
}

void SpacialSceneDemo::draw() const {
    Scene::draw();
}

SpacialSceneDemo::~SpacialSceneDemo() {
}

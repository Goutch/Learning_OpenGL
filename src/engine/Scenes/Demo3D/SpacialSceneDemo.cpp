//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
#include "Grass.h"
void SpacialSceneDemo::init(const Canvas &canvas, Renderer &renderer, Input &input){
    SpacialScene::init(canvas, renderer, input);
    ambient_light=Color(0.2,0.2,0.2,2);
    input.showCursor(false);
    //create cube_mesh mesh
    Geometry::make_cube(cube_mesh);
    Geometry::make_sphere(sphere_mesh,1,100,50);

    dragon_material.shine(30);
    dragon_material.damp(16);
    dragon_material.setColor(Color(0.7,0.4,0.4));
    //ground
    addEntity(new MeshRenderer(cube_mesh, ground_material, vec3(0, -.5, 0), vec3(0), vec3(1000, 1, 1000)));
    grass=new Grass();

    addEntity(grass);
    //sphere
    addEntity(new MeshRenderer(sphere_mesh, sphere_material, vec3(0, 5, 0)));
    //bunnies
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(10,0,0)));
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(-10,0,0)));
    auto P=new MeshRenderer(cube_mesh,player_material);
    P->transform.parent=&camera->transform;
    addEntity(P);
    //dragons
    dragon_material.shine(20);
    dragon_material.damp(16);
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, 10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, -10)));
    addEntity(new MeshRenderer(cube_mesh, dragon_material, vec3(0, 0.5, -10), vec3(0), vec3(12, 1, 8)));
    addEntity(new MeshRenderer(dragon_mesh, dragon_material, vec3(0, .9, 10)));

    //controller
    addEntity(new FPSController(camera->transform, vec3(0, 2, 2), vec3(0), vec3(1)));

    //Directional sun light

    sun = new DirectionalLight(Color(1,1,1),vec3(0, 2, 0), glm::radians(vec3(-45, -45, 0)));

    addLight(sun);
    mirror_material.setTexture(mirror_canvas.getFrameBuffer().getTexture());
    MeshRenderer* mirror=new MeshRenderer(
            mirror_quad,
            mirror_material,vec3(-20,2,0),
            vec3(0,3.1416/2,0),
            vec3(4));
    mirror_camera.parent=&mirror->transform;
    addEntity(mirror);
    mirror_camera.rotate(3.1416,vec3(0,1,0));
    mirror_camera.position(vec3(0,0,-.5));
    projection_mirror=glm::perspective<float>(glm::radians<float>(60),mirror_canvas.getPixelWidth()/mirror_canvas.getPixelHeight(),0.1,100);

}

void SpacialSceneDemo::update(float delta) {
    SpacialScene::update(delta);
    //mirror_camera.rotate(delta,vec3(0,1,0));
}

void SpacialSceneDemo::render() const {
    SpacialScene::render();
}

void SpacialSceneDemo::draw() const {

    mat4 vm=glm::inverse(mirror_camera.getMatrix());
    grass->getMaterial().getShader().bind();

    grass->getMaterial().getShader().loadUniform("mvp",
                                      projection_mirror *vm*
                                      grass->transform.getMatrix());
    grass->getMaterial().getShader().unbind();
    SpacialScene::draw();
    mirror_canvas.getFrameBuffer().bind();
    renderer->clear();
    mirror_canvas.getFrameBuffer().unbind();
    renderer->renderSpace(mirror_canvas.getFrameBuffer(),projection_mirror,glm::inverse(mirror_camera.getMatrix()));
    grass->getMaterial().getShader().bind();

    grass->getMaterial().getShader().loadUniform("mvp",
                                                 camera->getProjectionMatrix() *camera->getViewMatrix()*
                                                 grass->transform.getMatrix());
    grass->getMaterial().getShader().unbind();
    SpacialScene::draw();
}

SpacialSceneDemo::~SpacialSceneDemo() {
}

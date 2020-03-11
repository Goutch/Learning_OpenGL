//
// Created by User on 2020-01-18.
//
#include "SpacialSceneDemo.h"
#include "API_ALL.h"
#include "Grass.h"
void SpacialSceneDemo::init(const Canvas &canvas, Renderer &renderer, Input &input){
    Scene::init(canvas, renderer, input);
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
    grass=new Grass();

    instantiate(grass);
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

    mirror_camera=new Camera();
    instantiate(mirror_camera);
    mirror_material.setTexture(mirror_canvas.getFrameBuffer().getTexture());
    MeshRenderer* mirror=new MeshRenderer(
            mirror_quad,
            mirror_material,vec3(-20,2,0),
            vec3(0,3.1416/2,0),
            vec3(4));
    mirror_camera->setParent(mirror);
    instantiate(mirror);
    mirror_camera->transform.rotate(3.1416,vec3(0,1,0));
    mirror_camera->transform.position(vec3(0,0,-.5));

}

void SpacialSceneDemo::update(float delta) {
    Scene::update(delta);

}

void SpacialSceneDemo::render() const {
    Scene::render();
}

void SpacialSceneDemo::draw() const {

    mat4 vm=mirror_camera->getViewMatrix();
    grass->getMaterial().getShader().bind();

    grass->getMaterial().getShader().loadUniform("mvp",
                                      mirror_camera->getProjectionMatrix() *vm*
                                      grass->transform.getMatrix());
    grass->getMaterial().getShader().unbind();
    Scene::draw();
    mirror_canvas.getFrameBuffer().bind();
    renderer->clear();
    mirror_canvas.getFrameBuffer().unbind();
    renderer->render(mirror_canvas.getFrameBuffer(), mirror_camera->getProjectionMatrix(), vm);
    grass->getMaterial().getShader().bind();

    grass->getMaterial().getShader().loadUniform("mvp",
                                                 camera->getProjectionMatrix() *camera->getViewMatrix()*
                                                 grass->transform.getMatrix());
    grass->getMaterial().getShader().unbind();
    Scene::draw();
}

SpacialSceneDemo::~SpacialSceneDemo() {
}

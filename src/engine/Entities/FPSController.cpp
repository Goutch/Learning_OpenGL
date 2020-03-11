//
// Created by User on 2020-01-05.
//

#include "FPSController.h"
#include <API_ALL.h>


FPSController::FPSController(Camera &camera, vec3 position, vec3 rotation, vec3 scale) : Entity(position, rotation, scale) {
    this->camera=&camera;
    camera.setParent(this);
}

FPSController::FPSController(Camera &camera): Entity() {
    this->camera=&camera;
    camera.setParent(this);
}

void FPSController::init(Scene &scene) {
    Entity::init(scene);
    scene.getInput().showCursor(false);
}

void FPSController::update(float delta, Scene &scene) {
    Input& input= scene.getInput();
    const Canvas& canvas =scene.getCanvas();
    vec3 forward= vec3(0,0,-1) * 0.1f;
    vec3 right=vec3(1,0,0)*0.1f;
    vec3 up=vec3(0,1,0)*0.1f;
    vec3 dir=vec3(0);
    if (input.isKeyDown(GLFW_KEY_A)) {
        dir-=right;
    }
    if (input.isKeyDown(GLFW_KEY_D)) {
        dir+=right;
    }
    if (input.isKeyDown(GLFW_KEY_W)) {
        dir+=forward;
    }
    if (input.isKeyDown(GLFW_KEY_S)) {
        dir-=forward;
    }
    if (input.isKeyDown(GLFW_KEY_SPACE)) {
        dir+=up;
    }
    if (input.isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
        dir-=up;
    }
    transform.translate(dir*delta*speed);
    vec2 change=vec2(0.0f);

    auto width=(double)canvas.getPixelWidth();
    auto height=(double)canvas.getPixelHeight();

    float fov=scene.getCamera().getFOV();
    double aspect_ratio=height/width;

    double x,y;
    input.getMousePosition(x,y);
    change.x=(((width/2)-x)/width)*fov;
    change.y=(((height/2)-y)/height)*(fov*aspect_ratio);

    transform.rotate(quat(vec3(0,radians(change.x),0)));
    camera->transform.rotate(quat(vec3(radians(change.y),0,0)));

    input.setMousePosition(width/2,height/2);
}

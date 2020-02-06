//
// Created by User on 2020-01-05.
//

#include "FPSController.h"
#include "Core/Window.h"
#include "Core/SpacialScene.h"


#include <Core/Canvas.h>

FPSController::FPSController(Transform& camera,vec3 position, vec3 rotation, vec3 scale) : SpacialEntity(position, rotation, scale) {
    this->camera=&camera;
    this->camera->parent=&transform;
}

FPSController::FPSController(Transform& camera): SpacialEntity() {
    this->camera=&camera;
    this->camera->parent=&transform;
}

void FPSController::init(SpacialScene &scene) {
    SpacialEntity::init(scene);
    scene.getWindow().showCursor(false);
}

void FPSController::update(float delta, SpacialScene &scene) {
    Window& window=scene.getWindow();
    vec3 forward= vec3(0,0,-1) * 0.1f;
    vec3 right=vec3(1,0,0)*0.1f;
    vec3 up=vec3(0,1,0)*0.1f;
    vec3 dir=vec3(0);
    if (window.isKeyDown(GLFW_KEY_A)) {
        dir-=right;
    }
    if (window.isKeyDown(GLFW_KEY_D)) {
        dir+=right;
    }
    if (window.isKeyDown(GLFW_KEY_W)) {
        dir+=forward;
    }
    if (window.isKeyDown(GLFW_KEY_S)) {
        dir-=forward;
    }
    if (window.isKeyDown(GLFW_KEY_SPACE)) {
        dir+=up;
    }
    if (window.isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
        dir-=up;
    }
    transform.translate(dir*delta*speed);
    vec2 change=vec2(0.0f);
    double x,y;
    auto width=(double)window.getWidth();
    auto height=(double)window.getHeight();

    float fov=scene.getCamera().getFOV();
    double aspect_ratio=height/width;

    window.getMousePosition(x,y);
    change.x=(((width/2)-x)/width)*fov;
    change.y=(((height/2)-y)/height)*(fov*aspect_ratio);
    transform.rotate(quat(vec3(0,radians(change.x),0)));
    camera->rotate(quat(vec3(radians(change.y),0,0)));

    window.setMousePosition(width/2,height/2);
}

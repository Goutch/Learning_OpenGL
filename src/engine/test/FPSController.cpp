//
// Created by User on 2020-01-05.
//

#include "FPSController.h"
#include "core/Window.h"


FPSController::FPSController(float aspectRatio,float fov,vec3 position, vec3 rotation, vec3 scale) : Entity(position, rotation, scale) {
    this->aspect_ratio=aspectRatio;
    this->fov=fov;
}
void FPSController::render(Renderer &renderer) {

}

#include "glm/gtx/string_cast.hpp"
#include "iostream"
void FPSController::update(float delta, Window &window) {

    vec3 forward= vec3(0,0,-1) * 0.1f;
    vec3 right=vec3(1,0,0)*0.1f;
    vec3 up=vec3(0,1,0)*0.1f;

    if (window.isKeyDown(GLFW_KEY_A)) {
        transform.translate(-right);
    }
    if (window.isKeyDown(GLFW_KEY_D)) {
        transform.translate(right);
    }
    if (window.isKeyDown(GLFW_KEY_W)) {
        transform.translate(forward);
    }
    if (window.isKeyDown(GLFW_KEY_S)) {
        transform.translate(-forward);
    }
    if (window.isKeyDown(GLFW_KEY_SPACE)) {
        transform.translate(up);
    }
    if (window.isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
        transform.translate(-up);
    }

    vec2 change=vec2(0.0f);
    double x,y;
    float width=(float)window.getWidth();
    float height=(float)window.getHeight();

    window.getMousePosition(x,y);
    change.x=(((width/2)-x)/width)*fov;
    change.y=(((height/2)-y)/height)*(fov*aspect_ratio);
    transform.rotate(radians(change.x),vec3(0,1,0));
    window.showCursor(false);
    window.setMousePosition((double)window.getWidth()/2,(double)window.getHeight()/2);
}
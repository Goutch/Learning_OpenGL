//
// Created by User on 2020-01-26.
//
#include "Camera.h"
#include "Core/Canvas.h"
#include "Core/Scene.h"

Camera::Camera(vec3 position, vec3 rotation) : Entity(position, rotation, vec3(1)) {

}

void Camera::init(Scene &scene) {
    Entity::init(scene);
    this->canvas = &scene.getCanvas();
    canvas->subscribeSizeChange(*this);
    units.x=scene.getCanvas().getPixelWidth();
    units.y=scene.getCanvas().getPixelHeight();
    setProjectionPerspective(units.x,units.y);
}


void Camera::setProjectionPerspective(float width, float height) {
    this->projectionMode = PERSPECTIVE;
    units.x=width;
    units.y=height;
    double aspect_ratio = width / height;
    projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
}
void Camera::setProjectionOrthographic(float width, float height) {
    this->projectionMode = ORTHOGRAPHIC;
    units.x=width;
    units.y=height;
    double aspect_ratio = width / height;
    projection_matrix = glm::ortho<float>(-width / 2, width / 2, -(height / 2) / aspect_ratio,
                                          (height / 2) / aspect_ratio, -100, 100);
}

const mat4 &Camera::getProjectionMatrix() const {
    return projection_matrix;
}

mat4 Camera::getViewMatrix() const {
    return glm::inverse(transform.getMatrix());
}

float Camera::getFOV() const {
    return fov;
}

void Camera::onCanvasSizeChange(unsigned int width, unsigned int height) {
    units.x=width;
    units.y=height;
    if (projectionMode == ORTHOGRAPHIC)
        setProjectionOrthographic(units.x, units.y);
    else
        setProjectionPerspective(units.x,units.y);
}

void Camera::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    scene.getCanvas().unsubscribeSizeChange(*this);
}

void Camera::setFOV(float fov) {
    this->fov = fov;
    setProjectionPerspective(units.x,units.y);
}

Camera::ProjectionMode Camera::getProjectionMode() {
    return projectionMode;
}










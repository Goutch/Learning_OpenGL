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
    setProjectionPerspective();
}

void Camera::setProjectionPerspective() {
    this->projectionMode = PERSPECTIVE;
    double w = (float) canvas->getPixelWidth();
    double h = (float) canvas->getPixelHeight();
    double aspect_ratio = w / h;
    projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
}

void Camera::setProjectionOrtho(float width, float height) {
    this->projectionMode = ORTHOGRAPHIC;
    ortho_units.x=width;
    ortho_units.y=height;
    double w = (float) canvas->getPixelWidth();
    double h = (float) canvas->getPixelHeight();
    double aspect_ratio = w / h;
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
    if (projectionMode == ORTHOGRAPHIC)
        setProjectionOrtho(ortho_units.x,ortho_units.y);
    else
        setProjectionPerspective();
}

void Camera::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    scene.getCanvas().unsubscribeSizeChange(*this);
}

void Camera::setFOV(float fov) {
    this->fov = fov;
    setProjectionPerspective();
}

Camera::ProjectionMode Camera::getProjectionMode() {
    return projectionMode;
}








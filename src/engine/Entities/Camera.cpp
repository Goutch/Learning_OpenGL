//
// Created by User on 2020-01-26.
//

#include "Camera.h"
#include "Core/Viewport.h"
#include "Core/Scene.h"
Camera::Camera(const Viewport& viewport, Camera::ProjectionMode mode, vec3 position, vec3 rotation):Entity(position,rotation,vec3(1)) {
    this->projectionMode=mode;
    this->viewport=&viewport;
    viewport.subscribeSizeChange(*this);
    calculateProjectionMatrix();
}

Camera::Camera(const Viewport& viewport,vec3 position, vec3 rotation):Entity(position,rotation,vec3(1)) {
    this->viewport=&viewport;
    viewport.subscribeSizeChange(*this);
    calculateProjectionMatrix();
}
void Camera::setProjectionMode(ProjectionMode projectionMode) {
    this->projectionMode = projectionMode;
    calculateProjectionMatrix();
}
const mat4& Camera::getProjectionMatrix() const {
    return projection_matrix;
}
mat4 Camera::getViewMatrix() const {
    return glm::inverse(transform.getMatrix());
}
void Camera::calculateProjectionMatrix() {
    double w = (float) viewport->getPixelWidth();
    double h = (float) viewport->getPixelHeight();
    double aspect_ratio = w / h;
    if (projectionMode == PERSPECTIVE) {
        fov = 90;
        projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
    } else if (projectionMode == ORTHOGRAPHIC_PIXEL) {
        projection_matrix = viewport->getPixelProjection();
    } else {
        projection_matrix = glm::ortho<float>(-1, 1, -1 / aspect_ratio, 1 / aspect_ratio, -100, 100);

    }
}


void Camera::init(Scene &scene) {
    Entity::init(scene);
    this->viewport= &scene.getViewport();
    calculateProjectionMatrix();
}

float Camera::getFOV() const {
    return fov;
}

mat4 Camera::getCameraSpaceMatrix() const {
    return projection_matrix*inverse(transform.getMatrix());
}

void Camera::onViewportSizeChange(unsigned int width, unsigned int height) {
    calculateProjectionMatrix();
}

void Camera::destroy(Scene &scene) {
    Entity::destroy(scene);
    scene.getViewport().unsubscribeSizeChange(*this);
}





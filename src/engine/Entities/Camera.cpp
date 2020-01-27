//
// Created by User on 2020-01-26.
//

#include "Camera.h"
#include "Core/Viewport.h"
#include "Core/Scene.h"
Camera::Camera( Camera::ProjectionMode mode, vec3 position, vec3 rotation):Entity(position,rotation,vec3(0)) {
    this->projectionMode=mode;

}

Camera::Camera(vec3 position, vec3 rotation):Entity(position,rotation,vec3(0)) {

}
void Camera::setRenderMode(ProjectionMode projectionMode) {
    this->projectionMode = projectionMode;
    calculateProjectionMatrix();
}
const mat4& Camera::getProjectionMatrix() const {
    return projection_matrix;
}
mat4 Camera::getViewMatrix() const {
    return glm::inverse(transform.getMatrix());
}
mat4 Camera::getCameraSpaceMatrix() const {
    return projection_matrix*getViewMatrix();
}
void Camera::calculateProjectionMatrix() {
    float w = (float) viewport->getWidth();
    float h = (float) viewport->getHeight();
    double aspect_ratio = w / h;
    if (projectionMode == PERSPECTIVE) {
        fov = 90;
        projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
    } else if (projectionMode == ORTHOGRAPHIC_PIXEL) {
        projection_matrix = glm::ortho<float>(0, viewport->getWidth(), 0, viewport->getHeight(), -100, 100);
    } else {
        projection_matrix = glm::ortho<float>(-1, 1, -1 * aspect_ratio, 1 * aspect_ratio, -100, 100);

    }
}

void Camera::onViewportSizeChange(int width, int height) {

}

void Camera::init(Scene &scene) {
    Entity::init(scene);
    this->viewport= &scene.getViewport();
    calculateProjectionMatrix();
}





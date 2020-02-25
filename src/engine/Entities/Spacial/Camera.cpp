//
// Created by User on 2020-01-26.
//
#include "Camera.h"
#include "Core/Canvas.h"
#include "Core/SpacialScene.h"

Camera::Camera(vec3 position, vec3 rotation)  : SpacialEntity(position, rotation, vec3(1)){

}
void Camera::init(SpacialScene &scene) {
    SpacialEntity::init(scene);
    this->canvas=&scene.getCanvas();
    canvas->subscribeSizeChange(*this);
    setProjectionMode(ProjectionMode::PERSPECTIVE);
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
    double w = (float) canvas->getPixelWidth();
    double h = (float) canvas->getPixelHeight();
    double aspect_ratio = w / h;
    if (projectionMode == PERSPECTIVE) {
        projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
    } else if (projectionMode == ORTHOGRAPHIC_PIXEL) {
        projection_matrix = canvas->getPixelProjection();
    } else {
        projection_matrix = glm::ortho<float>(-1, 1, -1 / aspect_ratio, 1 / aspect_ratio, -100, 100);

    }
}




float Camera::getFOV() const {
    return fov;
}

void Camera::onCanvasSizeChange(unsigned int width, unsigned int height) {

    calculateProjectionMatrix();
}

void Camera::onDestroy(SpacialScene &scene) {
    SpacialEntity::onDestroy(scene);
    scene.getCanvas().unsubscribeSizeChange(*this);
}

void Camera::setFOV(float fov) {
    this->fov=fov;
    calculateProjectionMatrix();
}






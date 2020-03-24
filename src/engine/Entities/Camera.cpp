//
// Created by User on 2020-01-26.
//
#include <Math/BoundingBox.h>
#include "Camera.h"
#include "Core/Canvas.h"
#include "Core/Scene.h"

Camera::Camera(vec3 position, vec3 rotation) : Entity(position, rotation, vec3(1)) {

}

void Camera::init(Scene &scene) {
    Entity::init(scene);
    this->canvas = &scene.getCanvas();
    canvas->subscribeSizeChange(*this);
    units.x = scene.getCanvas().getPixelWidth();
    units.y = scene.getCanvas().getPixelHeight();
    setProjectionPerspective(units.x, units.y);
}


void Camera::setProjectionPerspective(float width, float height) {
    this->projectionMode = PERSPECTIVE;
    units.x = width;
    units.y = height;
    double aspect_ratio = width / height;
    projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 500.0f);
}

void Camera::setProjectionOrthographic(float width, float height) {
    this->projectionMode = ORTHOGRAPHIC;
    units.x = width;
    units.y = height;
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
    units.x = width;
    units.y = height;
    if (projectionMode == ORTHOGRAPHIC)
        setProjectionOrthographic(units.x, units.y);
    else
        setProjectionPerspective(units.x, units.y);
}

void Camera::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    scene.getCanvas().unsubscribeSizeChange(*this);
}

void Camera::setFOV(float fov) {
    this->fov = fov;
    setProjectionPerspective(units.x, units.y);
}

Camera::ProjectionMode Camera::getProjectionMode() {
    return projectionMode;
}

void Camera::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
}

void Camera::calculateFrustumPlanes() {
    mat4 m = projection_matrix * getViewMatrix();
    frustum_planes[0].set((vec4(m[0][3] + m[0][0], m[1][3] + m[1][0], m[2][3] + m[2][0], m[3][3] + m[3][0])));//left
    frustum_planes[1].set((vec4(m[0][3] - m[0][0], m[1][3] - m[1][0], m[2][3] - m[2][0], m[3][3] - m[3][0])));//right
    frustum_planes[3].set((vec4(m[0][3] + m[0][1], m[1][3] + m[1][1], m[2][3] + m[2][1], m[3][3] + m[3][1])));//bottom
    frustum_planes[2].set((vec4(m[0][3] - m[0][1], m[1][3] - m[1][1], m[2][3] - m[2][1], m[3][3] - m[3][1])));//top
    frustum_planes[4].set((vec4(m[0][3] + m[0][2], m[1][3] + m[1][2], m[2][3] + m[2][2], m[3][3] + m[3][2])));//near
    frustum_planes[5].set((vec4(m[0][3] - m[0][2], m[1][3] - m[1][2], m[2][3] - m[2][2], m[3][3] - m[3][2])));//far
}

bool Camera::isPointInFrustum(const vec3 &point) const {
    for (int i = 0; i < frustum_planes.size(); i++) {
        if (0 > frustum_planes[i].distance(point)) {
            return false;
        }
    }
    return true;
}

bool Camera::isBoundingBoxInFrustum(const BoundingBox &box) const {
    return isBoxInFrustum(box.pos, box.size.x,box.size.y,box.size.z);
}
bool Camera::isSphereInFrustum(const vec3& position,float radius) const{
    for (int i = 0; i < frustum_planes.size(); i++) {
        if (0 > frustum_planes[i].distance(position)+radius) {
            return false;
        }
    }
    return true;
}
bool Camera::isBoxInFrustum(const vec3 &position, float size_x, float size_y, float size_z) const {

    if (isPointInFrustum(position)) { return true; }
    if (isPointInFrustum(position + vec3(size_x,size_y,size_z))) { return true; }
    if (isPointInFrustum(position + vec3(size_x, 0.0f, 0.0f))) { return true; }
    if (isPointInFrustum(position + vec3(0.0f, size_y, 0.0f))) { return true; }
    if (isPointInFrustum(position + vec3(0.0f, 0.0f, size_z))) { return true; }
    if (isPointInFrustum(position + vec3(size_x, size_y, 0.0f))) { return true; }
    if (isPointInFrustum(position + vec3(0.0f, size_y, size_z))) { return true; }
    return isPointInFrustum(position + vec3(size_x, 0.0f, size_z));
}








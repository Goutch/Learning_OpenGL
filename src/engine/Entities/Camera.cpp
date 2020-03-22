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
void Camera::setProjectionOrtho(float width, float height) {
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
        setProjectionOrtho(units.x,units.y);
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

void Camera::update(float delta, Scene &scene) {
    Entity::update(delta, scene);
    calculateFrustumPlanes();
}

void Camera::calculateFrustumPlanes() {
    mat4 m=transpose(mat4(projection_matrix))*getViewMatrix();
    frustum_planes[0].set((m[3] + m[0]));//left
    frustum_planes[1].set((m[3] - m[0]));//right
    frustum_planes[3].set((m[3] + m[1]));//bottom
    frustum_planes[2].set((m[3] - m[1]));//top
    frustum_planes[4].set((m[3] + m[2]));//near
    frustum_planes[5].set((m[3] - m[2]));//far
}
bool Camera::isPointInFrustum(const vec3& point){
    for (int i = 0; i < frustum_planes.size(); i++) {
        if ( 0>frustum_planes[i].distance(point)) {
            return false;
        }
    }
    return true;
}

bool Camera::isBoundingBoxInFrustum(const BoundingBox &box) {
    if(isPointInFrustum(box.pos)){return true;}
    if(isPointInFrustum(box.pos+box.size)){return true;}
    if(isPointInFrustum(box.pos+(vec3(box.size.x,0,0)))){return true;}
    if(isPointInFrustum(box.pos+(vec3(0,box.size.y,0)))){return true;}
    if(isPointInFrustum(box.pos+(vec3(0,0,box.size.z)))){return true;}
    if(isPointInFrustum(box.pos+(vec3(box.size.x,box.size.y,0)))){return true;}
    if(isPointInFrustum(box.pos+(vec3(0,box.size.y,box.size.z)))){return true;}
    return isPointInFrustum(box.pos + (vec3(box.size.x, 0, box.size.z)));
}








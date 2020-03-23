//
// Created by User on 18-Mar.-2020.
//

#include "CameraFrustum.h"

CameraFrustum::CameraFrustum(Scene &scene) {
    this->pCamera = &scene.getCameraPtr();
}

void CameraFrustum::update() {
     m = (*pCamera)->getProjectionMatrix() * (*pCamera)->getViewMatrix();
    planes[0].set(m[3] + m[0]);//left
    planes[1].set(m[3] - m[0]);//right
    planes[3].set(m[3] + m[1]);//down
    planes[2].set(m[3] - m[1]);//top
    planes[4].set(m[2] + m[3]);//near
    //planes[5].set(m[3] - m[2]);//far

}

int CameraFrustum::boxInFrustum(const vec3 &center, float x, float y, float z) {
    int result = FRUSTUM_INSIDE;

    for (int i = 0; i < planes.size(); i++) {
        // Reset counters for corners in and out
        int out = 0;
        int in = 0;

        if (planes[i].distance(m*vec4(center + vec3(-x, -y, -z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(x, -y, -z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(-x, -y, z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(x, -y, z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(-x, y, -z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(x, y, -z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(-x, y, z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        if (planes[i].distance(m*vec4(center + vec3(x, y, z),1)) < 0) {
            out++;
        } else {
            in++;
        }

        // If all corners are out
        if (!in) {
            return FRUSTUM_OUTSIDE;
        }
            // If some corners are out and others are in
        else if (out) {
            result = FRUSTUM_INTERSECT;
        }
    }

    return (result);
}

int CameraFrustum::PointInFrustum(const vec3 &point) {
    {
        int result = FRUSTUM_INSIDE;

        for (int i = 0; i < planes.size(); i++) {
            if (planes[i].distance(point) < 0) {
                return FRUSTUM_OUTSIDE;
            }
        }

        return (result);
    }
}

CameraFrustum::~CameraFrustum() {

}

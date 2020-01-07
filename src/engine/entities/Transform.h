//
// Created by User on 2020-01-02.
//

#pragma once

#include "glm/gtx/quaternion.hpp"
#include <glm/gtx/transform.hpp>
#include "glm/gtx/matrix_decompose.hpp"
using namespace glm;
class Transform {

    mat4 transform_matrix=glm::mat4(1.0f);
    quat rot;

public:
    Transform* parent= nullptr;
    Transform();
    mat4 getMatrix() const;

    vec3 position();
    void position(const vec3& position);
    void translate(const vec3 & translation);

    void rotate(quat rotation);
    void rotate(float angle,vec3 axis);
    quat rotation();

    vec3 forward();
    vec3 right();
    vec3 up();
    void scale(vec3 scale);
    void setScale(vec3 scale);
    vec3 scale();
};



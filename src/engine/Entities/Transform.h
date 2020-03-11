//
// Created by User on 2020-01-02.
//

#pragma once

#include "glm/gtx/quaternion.hpp"
#include <glm/gtx/transform.hpp>
#include "glm/gtx/matrix_decompose.hpp"
using namespace glm;
class Transform {
    friend class Entity;
    mat4 transform_matrix=glm::mat4(1.0f);
    quat rot=glm::identity<quat>();
    Transform* parent= nullptr;
public:

    Transform();
    Transform(vec3 position,vec3 rotation,vec3 scale);
    mat4 getMatrix() const;

    vec3 position() const ;
    vec3 localPosition() const;
    void position(const vec3& position);
    void translate(const vec3 & translation);

    void rotate(const quat& rotation);
    void rotate(float angle,vec3 axis);

    quat rotation() const;
    void rotation(const quat& rotation);
    vec3 eulerRotation() const;

    vec3 forward() const;
    vec3 right() const;
    vec3 up() const;

    void scale(vec3 scale);
    vec3 scale() const;
    void setScale(vec3 scale);
};



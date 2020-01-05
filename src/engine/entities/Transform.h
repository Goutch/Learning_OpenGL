//
// Created by User on 2020-01-02.
//

#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
class Transform {
    mat4 transform_matrix=glm::mat4(1.0f);
    vec3 rot;
    vec3 pos;
    vec3 scale;


public:
    Transform();
    mat4 getMatrix();
    void translate(const vec3 & translation);
    void rotate(float angle,const  vec3  &axis);
};



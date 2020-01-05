//
// Created by User on 2020-01-02.
//

#pragma once
#include "../sml/sml.h"

class Transform {
    mat4 transform_matrix = mat4();
    vec3 rot = vec3();
    vec3 pos = vec3();
    vec3 scale = vec3();


public:
    Transform();
    mat4 getMatrix();
    void translate(const vec3 & translation);
    void rotate(float angle,const  vec3  &axis);
};



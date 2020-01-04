#pragma once
class vec3;

#include "string"
struct mat4 {
    float* data=new float[4*4];
    mat4();
    mat4(const mat4& other);
    mat4(const float* other);
    ~mat4();
    mat4& identity();
    mat4& inverse();
    void translate(vec3 translation);
    void rotate(vec3 rotation);
    void scale(vec3 scale);
    mat4 operator*(const mat4 &other) const;
    std::string toString();
};



#pragma once
class vec3;
class vec4;
#include "string"
struct mat4 {
    float* data=new float[4*4];
    mat4();
    mat4(const mat4& other);
    mat4(const float* other);
    void copy(const mat4& other);
    void copy(const float* other);
    ~mat4();
    mat4& identity();
    float determinant();

    mat4 inverse();
    void translate(vec3 translation);
    void rotate(vec3 rotation);
    void scale(vec3 scale);
    mat4 operator*(const mat4 &other) const;
    vec4 operator*(const vec4 &other) const;
    std::string toString();

private:
    float determinant(float m11,float m21,float m12,float m22);
    float determinant(float m11, float m21, float m31, float m12, float m22, float m32, float m13, float m23, float m33);
};




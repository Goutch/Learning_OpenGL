#pragma once

struct vec3 {
public:
    float x = 0, y = 0, z = 0;

    vec3(float x, float y, float z);
    void normalize();
    float dot(const vec3 &other) const;
    vec3 operator*(const vec3 &other) const;

    vec3 operator/(const vec3 &other) const;

    vec3 operator+(const vec3 &other) const;

    vec3 operator-(const vec3 &other) const;
};


#pragma once

struct vec3 {
    float data[3];
    float& x =data[0], y = data[1], z = data[2];
    vec3();
    vec3(const vec3& other);
    vec3(float x, float y, float z);

    void normalize();
    float dot(const vec3 &other) const;
    vec3 operator*(const vec3 &other) const;

    vec3 operator/(const vec3 &other) const;

    vec3 operator+(const vec3 &other) const;
    void operator+=(const vec3 &other);
    vec3 operator-(const vec3 &other) const;
};


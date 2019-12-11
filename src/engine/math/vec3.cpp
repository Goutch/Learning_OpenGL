//
// Created by User on 11-Dec.-2019.
//

#include "vec3.h"

vec3::vec3(float x, float y, float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}
void vec3::normalize() {
    float total=x+y+z;
    x=x/total;
    y=y/total;
    z=z/total;
}
vec3 vec3::operator*(const vec3 &other) const {
    return {x*other.x,y*other.y,z*other.z};
}
vec3 vec3::operator/(const vec3 &other) const  {
    return {x/other.x,y/other.y,z/other.z};
}
vec3 vec3::operator+(const vec3 &other) const  {
    return {x+other.x,y+other.y,z+other.z};
}
vec3 vec3::operator-(const vec3 &other) const  {
    return {x-other.x,y-other.y,z-other.z};
}

float vec3::dot(const vec3 &other) const {
    return (x*other.x)+(y*other.y)+(z*other.z);
}



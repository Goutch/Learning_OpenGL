//
// Created by User on 2020-01-02.
//

#include "vec4.h"
vec4::vec4(){
    this->x=0;
    this->y=0;
    this->z=0;
    this->w=0;
}
vec4::vec4(const vec4& other) {
    this->x=other.x;
    this->y=other.y;
    this->z=other.z;
    this->w=other.w;
}
vec4::vec4(float x, float y, float z,float w) {
    this->x=x;
    this->y=y;
    this->z=z;
    this->w=w;
}
void vec4::normalize() {
    float total=x+y+z+w;
    x=x/total;
    y=y/total;
    z=z/total;
    w=w/total;
}
vec4 vec4::operator*(const vec4 &other) const {
    return {x*other.x,y*other.y,z*other.z,w*other.w};
}
vec4 vec4::operator/(const vec4 &other) const  {
    return {x/other.x,y/other.y,z/other.z,w/other.w};
}
vec4 vec4::operator+(const vec4 &other) const  {
    return {x+other.x,y+other.y,z+other.z,w+other.w};
}
void vec4::operator+=(const vec4 &other)  {
    x+=other.x;
    y+=other.y;
    z+=other.z;
    w+=other.w;
}
vec4 vec4::operator-(const vec4 &other) const  {
    return {x-other.x,y-other.y,z-other.z,w-other.w};
}

float vec4::dot(const vec4 &other) const {
    return (x*other.x)+(y*other.y)+(z*other.z)+(w*other.w);
}

std::string vec4::toString() {
    return  {"("+ std::to_string(x) + ","+std::to_string(y) +"," +std::to_string(z)+","+std::to_string(w)+")" };
}

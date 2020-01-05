//
// Created by User on 11-Dec.-2019.
//

#include "vec3.h"

vec3::vec3(){
}
vec3::vec3(const vec3& other) {
    this->x=other.x;
    this->y=other.y;
    this->z=other.z;
}
vec3::vec3(const float (& other)[3]) {
    data[0]=other[0];
    data[1]=other[1];
    data[2]=other[2];
}
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
vec3 vec3::normalized() const {
    float total=x+y+z;
    return {x/total,y/total,z/total};
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
void vec3::operator+=(const vec3 &other)  {
   x+=other.x;
   y+=other.y;
   z+=other.z;
}
vec3 vec3::operator-(const vec3 &other) const  {
    return {x-other.x,y-other.y,z-other.z};
}

float vec3::dot(const vec3 &other) const {
    return (x*other.x)+(y*other.y)+(z*other.z);
}
std::string vec3::toString() {
    return  {"("+ std::to_string(x) + ","+std::to_string(y) +"," +std::to_string(z)+")" };
}




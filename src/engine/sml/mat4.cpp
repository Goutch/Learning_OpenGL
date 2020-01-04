//
// Created by User on 11-Dec.-2019.
//

#include "mat4.h"
#include "vec3.h"
#include "array"
mat4::mat4() {
    identity();
}

mat4::mat4(const mat4 &other) {
    for (int i = 0; i < 16; ++i) {
        data[i] = other.data[i];
    }
}

mat4::mat4(const float *other) {
    for (int i = 0; i < 16; ++i) {
        data[i] = other[i];
    }
}

mat4::~mat4() {
    delete[] data;
}

mat4 &mat4::identity() {
    for (int i = 0; i < 16; ++i) {
        if (i == 0 || i == 5 || i == 10 || i == 15) {
            data[i] = 1;
        } else
            data[i] = 0;
    }
    return *this;
}

mat4 &mat4::inverse() {
    //TODO:implement this
    return *this;
}

void mat4::translate(vec3 translation) {
    //TODO:implement this
}

void mat4::rotate(vec3 rotation) {
    //TODO:implement this
}

void mat4::scale(vec3 scale) {
    //TODO:implement this
}

mat4 mat4::operator*(const mat4 &other) const {
    auto results=std::array<float,16>();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            results[(i * 4) + j] = (data[i] * other.data[j]) +
                                       (data[i + 1] * other.data[j + 4]) +
                                       (data[i + 2] * other.data[j + 8]) +
                                       (data[i + 3] * other.data[j + 12]);
        }
    }
    return {results.data()};
}
 std::string mat4::toString() {
    std::string s="";
    for (int i = 0; i < 4; ++i) {
        s+="["+std::to_string(data[0+(i*4)])+"  "+std::to_string(data[1+(i*4)])+"  "+std::to_string(data[2+(i*4)])+"  "+std::to_string(data[3+(i*4)])+"]\n";
    }
    return s;
}



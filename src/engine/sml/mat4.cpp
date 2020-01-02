//
// Created by User on 11-Dec.-2019.
//

#include "mat4.h"
#include "vec3.h"

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

mat4& mat4::identity() {
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



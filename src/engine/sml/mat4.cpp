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
    copy(other);
}

mat4::mat4(const float *other) {
    copy(other);
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

mat4 mat4::inverse() {
    float det = 1 / determinant();
    mat4 inverse_mat = mat4();
    inverse_mat.data[0] =
            determinant(data[5], data[6], data[7],
                        data[9], data[10], data[11],
                        data[13], data[14], data[15]) * det;
    inverse_mat.data[1] =
            -determinant(data[4], data[6], data[7],
                         data[8], data[10], data[11],
                         data[12], data[14], data[15]) * det;
    inverse_mat.data[2] =
            determinant(data[4], data[5], data[7],
                        data[8], data[9], data[11],
                        data[12], data[13], data[15]) * det;
    inverse_mat.data[3] =
            -determinant(data[4], data[5], data[6],
                         data[8], data[9], data[10],
                         data[12], data[13], data[14]) * det;
    inverse_mat.data[4] =
            -determinant(data[1], data[2], data[3],
                         data[9], data[10], data[11],
                         data[13], data[14], data[15]) * det;
    inverse_mat.data[5] =
            determinant(data[0], data[2], data[3],
                        data[8], data[10], data[11],
                        data[12], data[14], data[15]) * det;
    inverse_mat.data[6] =
            -determinant(data[0], data[1], data[3],
                         data[8], data[9], data[11],
                         data[12], data[13], data[15]) * det;
    inverse_mat.data[7] =
            determinant(data[0], data[1], data[2],
                        data[8], data[9], data[10],
                        data[12], data[13], data[14]) * det;
    inverse_mat.data[8] =
            determinant(data[1], data[2], data[3],
                        data[5], data[6], data[7],
                        data[13], data[14], data[15]) * det;
    inverse_mat.data[9] =
            -determinant(data[0], data[2], data[3],
                         data[4], data[6], data[7],
                         data[12], data[14], data[15]) * det;
    inverse_mat.data[10] =
            determinant(data[0], data[1], data[3],
                        data[4], data[5], data[7],
                        data[12], data[13], data[15]) * det;
    inverse_mat.data[11] =
            -determinant(data[0], data[1], data[2],
                         data[4], data[5], data[6],
                         data[12], data[13], data[14]) * det;
    inverse_mat.data[12] =
            -determinant(data[1], data[2], data[3],
                         data[5], data[6], data[7],
                         data[9], data[10], data[11]) * det;
    inverse_mat.data[13] =
            determinant(data[0], data[2], data[3],
                        data[4], data[6], data[7],
                        data[8], data[10], data[11]) * det;
    inverse_mat.data[14] =
            -determinant(data[0], data[1], data[3],
                         data[4], data[5], data[7],
                         data[8], data[9], data[11]) * det;
    inverse_mat.data[15] =
            determinant(data[0], data[1], data[2],
                        data[4], data[5], data[6],
                        data[8], data[9], data[10]) * det;
    float temp_value;
    temp_value = inverse_mat.data[4];
    inverse_mat.data[4] = inverse_mat.data[1];
    inverse_mat.data[1] = temp_value;

    temp_value = inverse_mat.data[8];
    inverse_mat.data[8] = inverse_mat.data[2];
    inverse_mat.data[2] = temp_value;

    temp_value = inverse_mat.data[12];
    inverse_mat.data[12] = inverse_mat.data[3];
    inverse_mat.data[3] = temp_value;

    temp_value = inverse_mat.data[9];
    inverse_mat.data[9] = inverse_mat.data[6];
    inverse_mat.data[6] = temp_value;

    temp_value = inverse_mat.data[13];
    inverse_mat.data[13] = inverse_mat.data[7];
    inverse_mat.data[7] = temp_value;

    temp_value = inverse_mat.data[14];
    inverse_mat.data[14] = inverse_mat.data[11];
    inverse_mat.data[11] = temp_value;

    return inverse_mat;
}

void mat4::translate(vec3 translation) {

        data[3] += translation.x;
        data[7] += translation.y;
        data[11] += translation.z;

}

void mat4::rotate(vec3 rotation) {
    //TODO:implement this
}

void mat4::scale(vec3 scale) {
    //TODO:implement this
}

mat4 mat4::operator*(const mat4 &other) const {
    auto results = std::array<float, 16>();
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

mat4 mat4::operator*(const vec4 &other) const {

}

mat4 mat4::operator*(const vec3 &other) const {

}

std::string mat4::toString() {
    std::string s = "";
    for (int i = 0; i < 4; ++i) {
        s += "[" + std::to_string(data[0 + (i * 4)]) + "  " + std::to_string(data[1 + (i * 4)]) + "  " +
             std::to_string(data[2 + (i * 4)]) + "  " + std::to_string(data[3 + (i * 4)]) + "]\n";
    }
    return s;
}

float mat4::determinant() {

    return (data[0] *
            determinant(data[5], data[6], data[7], data[9], data[10], data[11], data[13], data[14], data[15])) -
           (data[1] *
            determinant(data[4], data[6], data[7], data[8], data[10], data[11], data[12], data[14], data[15])) +
           (data[2] *
            determinant(data[4], data[5], data[7], data[8], data[9], data[11], data[12], data[13], data[15])) -
           (data[3] *
            determinant(data[4], data[5], data[6], data[8], data[9], data[10], data[12], data[13], data[14]));
}

float mat4::determinant(float m11, float m21, float m12, float m22) {
    return (m11 * m22) - (m12 * m21);
}

float
mat4::determinant(float m11, float m21, float m31, float m12, float m22, float m32, float m13, float m23,
                  float m33) {
    return (m11 * determinant(m22, m32, m23, m33)) - (m21 * determinant(m12, m32, m13, m33)) +
           (m31 * determinant(m12, m22, m13, m23));
}

void mat4::copy(const mat4 &other) {
    for (int i = 0; i < 16; ++i) {
        data[i] = other.data[i];
    }
}

void mat4::copy(const float *other) {
    for (int i = 0; i < 16; ++i) {
        data[i] = other[i];
    }
}




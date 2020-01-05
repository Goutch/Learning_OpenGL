//
// Created by User on 11-Dec.-2019.
//
#include "math.h"
#include "mat4.h"
#include "sml/vector/vec3.h"
#include "sml/vector/vec4.h"

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
    int indexes[9];
    float sign=1;
    for (int i = 0; i < 16; ++i) {
        sign*=-1;
        if(i%4==0)
        {
            sign*=-1;
        }
        getSubMatrixIndexes(i, indexes);
        inverse_mat.data[i] =
                sign*determinant(data[indexes[0]], data[indexes[3]], data[indexes[6]],
                            data[indexes[1]], data[indexes[4]], data[indexes[7]],
                            data[indexes[2]], data[indexes[5]], data[indexes[8]]) * det;

    }
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
    vec4 t = (*this) * vec4(translation.x, translation.y, translation.z, 1);
    data[12] += t.x;
    data[13] += t.y;
    data[14] += t.z;

}

void mat4::rotate(const float angle, const vec3 &axis) {

    float const c = cos(angle);
    float const s = sin(angle);
    vec3 n_axis=axis.normalized();
    mat4 result=mat4();

    result.data[0] = c + (1 - c) * n_axis.x * n_axis.x;
    result.data[1] = (1 - c) * n_axis.x * n_axis.y + s * n_axis.z;
    result.data[2] = (1 - c) * n_axis.x * n_axis.z - s * n_axis.y;

    result.data[4] = (1 - c) * n_axis.y * n_axis.x - s * n_axis.z;
    result.data[5] = c + (1 - c) * n_axis.y * n_axis.y;
    result.data[6] = (1 - c) * n_axis.y * n_axis.z + s * n_axis.x;

    result.data[8] = (1 - c) * n_axis.z * n_axis.x + s * n_axis.y;
    result.data[9] = (1 - c) * n_axis.z * n_axis.y - s * n_axis.x;
    result.data[10] = c + (1 - c) * n_axis.z * n_axis.z;

    copy( (*this)*result);
}

void mat4::scale(vec3 scale) {
    //TODO:implement this
}

mat4 mat4::operator*(const mat4 &other) const {
    auto results = mat4();
    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r) {
            int index=(c * 4) + r;
            int index_row = index % 4;
            int index_column = (index - index % 4) ;
            results.data[index] = (data[index_row] * other.data[index_column]) +
                                        (data[index_row+4] * other.data[index_column+1]) +
                                        (data[index_row+8] * other.data[index_column+2]) +
                                        (data[index_row+12] * other.data[index_column+3]);
        }
    }
    return results;
}

vec4 mat4::operator*(const vec4 &other) const {
    vec4 result = vec4();

    for (int i = 0; i < 4; ++i) {
        result.data[i] = (data[(i * 4)] * other.data[0]) + (data[(i * 4) + 1] * other.data[1]) +
                         (data[(i * 4) + 2] * other.data[2]) + (data[(i * 4) + 3] * other.data[3]);

    }
    return result;
}

std::string mat4::toString() {
    std::string s = "";
    for (int i = 0; i < 4; ++i) {
        s += "[" +
             std::to_string(data[0 + i]) + "  " +
             std::to_string(data[4 + i]) + "  " +
             std::to_string(data[8 + i]) + "  " +
             std::to_string(data[12 + i]) +
             "]\n";
    }
    return s;
}

float mat4::determinant() {

    return (data[0] *
            determinant(data[5], data[9], data[13],
                        data[6], data[10], data[14],
                        data[7], data[11], data[15]))
           - (data[4] *
              determinant(data[1], data[9], data[13],
                          data[2], data[10], data[14],
                          data[3], data[11], data[15]))
           + (data[8] *
              determinant(data[1], data[5], data[13],
                          data[2], data[6], data[14],
                          data[3], data[7], data[15]))
           - (data[12] *
              determinant(data[1], data[5], data[9],
                          data[2], data[6], data[10],
                          data[3], data[7], data[11]));
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

void mat4::getSubMatrixIndexes(int index, int (&array)[9]) {
    int count = 0;
    int index_row = index % 4;
    int index_column = (index - index % 4) / 4;
    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r) {
            if (c != index_column && r != index_row) {
                array[count] = (c * 4) + r;
                count++;
            }
        }
    }
}







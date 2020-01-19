//
// Created by User on 2020-01-18.
//

#pragma once

#include "glm/vec4.hpp"
struct Color {
    const static Color WHITE;
    const static Color BLACK;
    const static Color RED;
    const static Color GREEN;
    const static Color BLUE;

    glm::vec4 data;
    float& r=data[0];
    float& g=data[1];
    float& b=data[2];
    float& a=data[3];
public:
    Color(float r=0,float g=0,float b=0, float a=1);
    Color(const Color& other);
    void operator=(const Color& other);
};



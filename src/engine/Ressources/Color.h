//
// Created by User on 2020-01-18.
//

#pragma once

#include "glm/vec4.hpp"
class Color:public glm::vec4 {
public:
    const static Color WHITE;
    const static Color BLACK;
    const static Color RED;
    const static Color GREEN;
    const static Color BLUE;

    Color(float r=0,float g=0,float b=0, float a=1);

    Color& operator=(const Color& color) noexcept;
};



//
// Created by User on 2020-01-18.
//

#include "Color.h"
const Color Color::WHITE=Color(1,1,1,1);
const Color Color::BLACK=Color(0,0,0,1);
const Color Color::RED=Color(1,0,0,1);
const Color Color::GREEN=Color(0,1,0,1);
const Color Color::BLUE=Color(0,0,1,1);

Color::Color(float r, float g, float b, float a) {
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

Color &Color::operator=(const Color & color) noexcept {
    this->r = color.r;
    this->g = color.g;
    this->b= color.b;
    this->a = color.a;
    return *this;
}





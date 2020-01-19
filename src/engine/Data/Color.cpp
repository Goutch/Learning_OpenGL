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

Color::Color(const Color &other) {
    this->data[0]=other.data[0];
    this->data[1]=other.data[1];
    this->data[2]=other.data[2];
    this->data[3]=other.data[3];
}

void Color::operator=(const Color &other) {
    this->data[0]=other.data[0];
    this->data[1]=other.data[1];
    this->data[2]=other.data[2];
    this->data[3]=other.data[3];
}


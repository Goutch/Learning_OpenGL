//
// Created by User on 2019-11-24.
//

#include "Color.h"

Color::Color(float r, float g, float b, float a) {
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}
Color::Color(float r, float g, float b) {
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=1;
}
Color::~Color() {

}

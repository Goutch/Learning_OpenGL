//
// Created by User on 11-Dec.-2019.
//

#include "MathTest.h"
#include "sml/vec3.h"
#include "iostream"
void MathTest::init(Window &window, Renderer &renderer) {
    this->window = &window;
    this->renderer = &renderer;
    vec3 v1=vec3(2,4,8);
    vec3 v2=vec3(2,2,2);
    vec3 v3=v1+v2;
    std::cout << "(" << v3.x << "," << v3.y << "," << v3.z<<")" << std::endl;
}

void MathTest::update() {

}

void MathTest::render() {

}

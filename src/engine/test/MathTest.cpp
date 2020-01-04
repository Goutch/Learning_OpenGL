//
// Created by User on 11-Dec.-2019.
//

#include "MathTest.h"
#include "sml/sml.h"
#include "iostream"
void MathTest::init(Window &window, Renderer &renderer) {
    this->window = &window;
    this->renderer = &renderer;
    vec3 v1=vec3(2,4,8);
    vec3 v2=vec3(2,2,2);
    vec3 v3=v1+v2;
    std::cout << v3.toString() << std::endl;
    mat4 m1=mat4();
    mat4 m2=mat4();
    for (int i = 0; i < 16; ++i) {
        m1.data[i]=i;
        m2.data[i]=i;
    }
    mat4 r=m1*m2;
    std::cout<<m1.toString()<<std::endl;
    std::cout<<m2.toString()<<std::endl;
    std::cout<<r.toString()<<std::endl;
}

void MathTest::update() {

}

void MathTest::render() {

}

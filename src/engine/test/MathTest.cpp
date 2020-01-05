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

    mat4 invsMat=mat4();


    invsMat.data[0]=1;invsMat.data[1]=0;invsMat.data[2]=0;invsMat.data[3]=1;
    invsMat.data[4]=0;invsMat.data[5]=2;invsMat.data[6]=1;invsMat.data[7]=2;
    invsMat.data[8]=2;invsMat.data[9]=1;invsMat.data[10]=0;invsMat.data[11]=1;
    invsMat.data[12]=2;invsMat.data[13]=0;invsMat.data[14]=1;invsMat.data[15]=4;

    std::cout<<"mat:"<<invsMat.toString()<<std::endl;
    std::cout<<"invs:"<<invsMat.inverse().toString()<<std::endl;

}

void MathTest::update() {

}

void MathTest::render() {

}

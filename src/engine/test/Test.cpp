//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
Test::Test()
: Game()
{

}
void Test::init() {
    for (int i = 0; i < vaos.size(); ++i) {
        float vertices[8] = {
                ((float) i * (0.5f / vaos.size())), -0.5f,
                ((float) i * (0.5f / vaos.size())), 0.5f,
                (((float) i * (0.5f / vaos.size())) + (1.0f / vaos.size())), 0.5f,
                (((float) i * (0.5f / vaos.size())) + (1.0f / vaos.size())), -0.5f
        };
        float colors[12] = {
                0, 0, 1,
                0, 1, 1,
                1, 1, 0,
                1, 0, 0
        };
        vaos.at(i) = new VAO();
        vaos.at(i)->put(0, 2, vertices, 8);
        vaos.at(i)->put(1, 3, colors, 12);
    }
}

void Test::update(Window &window) {

}

void Test::render(Renderer &renderer) {
    for (auto &vao : vaos) {
        renderer.addToRenderQueue(vao);
    }
}

Test::~Test() {
    for (int i = 0; i < vaos.size(); ++i) {
        delete vaos[i];
    }
}

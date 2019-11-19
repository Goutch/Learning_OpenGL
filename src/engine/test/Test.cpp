//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include <vector>

Test::Test()
        : Game() {

}

void Test::init() {


    for (int i = 0; i < 1; ++i) {
        auto vert = std::vector<float>();
        vert.push_back(-0.5);vert.push_back(-0.5);vert.push_back(0);
        vert.push_back(-0.5);vert.push_back(0.5f);vert.push_back(0);
        vert.push_back(0.5f);vert.push_back(0.5f);vert.push_back(0);
        vert.push_back(0.5f);vert.push_back(-0.5);vert.push_back(0);

        float colors[12] = {
                0, 0, 1,
                0, 1, 1,
                1, 1, 0,
                1, 0, 0
        };
        objects.push_back(new Mesh());
        objects[i]->vertices(vert.data(), vert.size()).colors(colors, 12);
    }
}

void Test::update(Window &window) {

}

void Test::render(Renderer &renderer) {
    for (auto &mesh : objects) {
        renderer.addToRenderQueue(mesh);
    }
}

Test::~Test() {
    for (auto &mesh : objects) {
        delete mesh;
    }
    objects.clear();
}

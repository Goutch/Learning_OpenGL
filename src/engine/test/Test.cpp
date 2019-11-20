//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"

Test::Test()
        : Game() {

}

void Test::init() {
    auto vert = std::vector<float>();
    vert.push_back(-0.5);
    vert.push_back(-0.5);
    vert.push_back(0);
    vert.push_back(-0.5);
    vert.push_back(0.5f);
    vert.push_back(0);
    vert.push_back(0.5f);
    vert.push_back(0.5f);
    vert.push_back(0);
    vert.push_back(0.5f);
    vert.push_back(-0.5);
    vert.push_back(0);

    float colors[12] = {0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0};

    quad.vertices(vert.data(), vert.size()).colors(colors, 12);
    for (int i = 0; i < 1; ++i) {


        entities.push_back(new MeshRenderer(quad, shader, glm::vec3(i, 0, 0)));
    }

}

void Test::update(Window &window) {

}

void Test::render(Renderer &renderer) {
    for (auto &e : entities) {
        e->render(renderer);
    }
}

Test::~Test() {
    for (auto e : entities) {
        delete e;
    }
    entities.clear();
}

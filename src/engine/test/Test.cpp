//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"
#include "graphics/shaders/BaseShader.h"
#include "graphics/Mesh.h"
#include "core/Window.h"
#include "core/Renderer.h"
#include <cmath>
Test::Test()
        : Game() {
}

void Test::init() {
    shader=new BaseShader();
    quad=new Mesh();
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

    quad->vertices(vert.data(), vert.size()).colors(colors, 12);
    for (int i = 0; i < 5; ++i) {
        entities.push_back(new MeshRenderer(*quad, *shader, glm::vec3(0, 0, 0)));
        entities[i]->getTranform().rotate(glm::vec3(0,0,1),(M_PI/8)*i);


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
    delete shader;
    delete quad;
}

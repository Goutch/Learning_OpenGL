//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"
#include "entities/SpriteRenderer.h"
#include "graphics/Sprite.h"
#include "graphics/Texture.h"
#include "graphics/shaders/BaseShader.h"
#include "graphics/Mesh.h"
#include "core/Window.h"
#include "core/Renderer.h"
#include <cmath>

Test::Test()
        : Game() {
}

void Test::init() {
    shader = new BaseShader();
    quad = new Mesh();

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

    auto colors = std::vector<float>();
    colors.push_back(1);
    colors.push_back(1);
    colors.push_back(1);

    colors.push_back(1);
    colors.push_back(0);
    colors.push_back(0);

    colors.push_back(0);
    colors.push_back(1);
    colors.push_back(0);

    colors.push_back(0);
    colors.push_back(0);
    colors.push_back(1);

    auto indices = std::vector<unsigned int>();
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);

    quad->vertices(vert.data(), vert.size())
            .colors(colors.data(), colors.size())
            .indices(indices.data(), indices.size());

    for (int i = 0; i < 0; ++i) {
        entities.push_back(new MeshRenderer(quad, shader, glm::vec3(0, 0, 0)));
        //entities[i]->transform.rotate(glm::vec3(0, 0, 1), (0.01) * i);
    }
    wall=new Texture("../res/wall.jpg");
    stone=new Texture("../res/stone.jpg");
    stone->bind(1);
    sprite=new Sprite(wall);
    for (int j = 0; j < 1; ++j) {
        entities.push_back(new SpriteRenderer(sprite,shader,glm::vec3(0, 0, 0)));
    }
    //
}

void Test::update(Window &window) {

}

void Test::render(Renderer &renderer) {
    for (auto &e : entities) {
        e->render(renderer);
    }
}

Test::~Test() {
    stone->unbind(1);
    for (auto e : entities) {
        delete e;
    }
    entities.clear();
    delete wall;
    delete stone;
    delete sprite;
    delete shader;
    delete quad;
}

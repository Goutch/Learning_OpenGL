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

Test::Test()
        : Game() {
}

void Test::init() {
    shader = new BaseShader();
    quad = new Mesh();
    wall=new Texture("../res/wall.jpg");
    wall->bind(0);
    sprite=new Sprite(wall);

    auto vert = std::vector<float>();
    vert.push_back(-.5);vert.push_back(-.5);vert.push_back(0);
    vert.push_back(-.5);vert.push_back(.5f);vert.push_back(0);
    vert.push_back(.5f);vert.push_back(.5f);vert.push_back(0);
    vert.push_back(.5f);vert.push_back(-.5);vert.push_back(0);

    auto colors = std::vector<float>();
    colors.push_back(1);colors.push_back(1);colors.push_back(1);
    colors.push_back(1);colors.push_back(0);colors.push_back(0);
    colors.push_back(0);colors.push_back(1);colors.push_back(0);
    colors.push_back(0);colors.push_back(0);colors.push_back(1);

    auto indices = std::vector<unsigned int>();
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);

    quad->vertices(vert.data(), vert.size()).colors(colors.data(), colors.size()).indices(indices.data(), indices.size());
    entities.push_back(new MeshRenderer(quad, shader, glm::vec3(0, 0, -1)));
}
Window w;
void Test::update(Window &window) {
    w=window;
    entities[0]->transform.rotate(glm::vec3(0,1,0),0.01f);
}

void Test::render(Renderer &renderer) {
    if(w.isKeyDown(GLFW_KEY_0))
    {
        renderer.setRenderMode(w,Renderer::ORTHOGRAPHIC);
    }
    if(w.isKeyDown(GLFW_KEY_9))
    {
        renderer.setRenderMode(w,Renderer::PERSPECTIVE);
    }
    for (auto &e : entities) {
        e->render(renderer);
    }
}

Test::~Test() {
    stone->unbind(0);
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

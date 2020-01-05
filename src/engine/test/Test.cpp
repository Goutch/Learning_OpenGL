//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"

#include "graphics/data/Sprite.h"
#include "graphics/data/Texture.h"
#include "graphics/shaders/EntityShader.h"
#include "graphics/data/Mesh.h"
#include "core/Window.h"
#include "core/Renderer.h"
Test::Test()
        : Game() {
}

void Test::init(Window &window,Renderer &renderer) {
    this->renderer=&renderer;
    this->window=&window;
    shader = new EntityShader();
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
    renderer.setCamera(&camera);
    quad->vertices(vert.data(), vert.size()).colors(colors.data(), colors.size()).indices(indices.data(), indices.size());
    entities.push_back(new MeshRenderer(quad, shader, vec3(0, 0, -0.5f)));
}

void Test::update() {
    entities[0]->transform.rotate(vec3(0,0.01f,0));

    if(window->isKeyDown(GLFW_KEY_A))
    {
        camera.translate(vec3(-0.1,0,0));
    }
    if(window->isKeyDown(GLFW_KEY_D))
    {
        camera.translate(vec3(0.1,0,0));
    }
}

void Test::render() {
    if(window->isKeyDown(GLFW_KEY_0))
    {
        renderer->setRenderMode(*window,Renderer::ORTHOGRAPHIC);
    }
    if(window->isKeyDown(GLFW_KEY_9))
    {
        renderer->setRenderMode(*window,Renderer::PERSPECTIVE);
    }
    for (auto &e : entities) {
        e->render(*renderer);
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

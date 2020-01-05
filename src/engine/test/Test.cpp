//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"


#include "graphics/data/Texture.h"

#include "core/Window.h"
#include "core/Renderer.h"

Test::Test()
        : Game() {
}

void Test::init(Window &window, Renderer &renderer) {
    this->renderer = &renderer;
    this->window = &window;
    mesh=new Mesh();
    shader=new EntityShader();
    camera=new Camera(vec3(0,0,0));
    auto vert = std::vector<float>();
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);

    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);

    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);

    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);

    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);

    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);
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
    for (int i = 0; i < vert.size() / 3; ++i) {
        indices.push_back(i);
    }

    renderer.setCamera(*camera);
    mesh->vertices(vert.data(), vert.size()).colors(colors.data(), colors.size()).indices(indices.data(),
                                                                                         indices.size());
    entities.push_back(new MeshRenderer(*mesh, *shader, vec3(0, 0, -2.0f)));
}

void Test::update() {
    if (window->isKeyDown(GLFW_KEY_E)) {
        entities[0]->transform.rotate(0.05, vec3(0, 1, 0));
    }
    if (window->isKeyDown(GLFW_KEY_Q)) {
        entities[0]->transform.rotate(-0.05, vec3(0, 1, 0));
    }
    if (window->isKeyDown(GLFW_KEY_Z)) {
        entities[0]->transform.rotate(0.05, vec3(1, 0, 0));
    }
    if (window->isKeyDown(GLFW_KEY_X)) {
        entities[0]->transform.rotate(-0.05, vec3(1, 0, 0));
    }
    if (window->isKeyDown(GLFW_KEY_C)) {
        entities[0]->transform.rotate(0.05, vec3(0, 0, 1));
    }
    if (window->isKeyDown(GLFW_KEY_V)) {
        entities[0]->transform.rotate(-0.05, vec3(0, 0, 1));
    }
    if (window->isKeyDown(GLFW_KEY_A)) {
        camera->translate(vec3(-0.1, 0, 0));
    }
    if (window->isKeyDown(GLFW_KEY_D)) {
        camera->translate(vec3(0.1, 0, 0));
    }
    if (window->isKeyDown(GLFW_KEY_W)) {
        camera->translate(vec3(0, 0, -0.1));
    }
    if (window->isKeyDown(GLFW_KEY_S)) {
        camera->translate(vec3(0, 0, 0.1));
    }
    if (window->isKeyDown(GLFW_KEY_SPACE)) {
        camera->translate(vec3(0, 0.1, 0));
    }
    if (window->isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
        camera->translate(vec3(0, -0.1, 0));
    }
}

void Test::render() {
    if (window->isKeyDown(GLFW_KEY_0)) {
        renderer->setRenderMode(*window, Renderer::ORTHOGRAPHIC);
    }
    if (window->isKeyDown(GLFW_KEY_9)) {
        renderer->setRenderMode(*window, Renderer::PERSPECTIVE);
    }
    for (auto &e : entities) {
        e->render(*renderer);
    }
}

Test::~Test() {
    delete camera;
    delete mesh;
    delete shader;
    delete[]entities.data();
    entities.clear();
}

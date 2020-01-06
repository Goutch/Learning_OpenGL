//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"

#include "graphics/data/Texture.h"

#include "core/Window.h"
#include "core/Renderer.h"
#include "FPSController.h"

Test::Test()
        : Game() {
}

void Test::init(Window &window, Renderer &renderer) {
    this->renderer = &renderer;
    this->window = &window;
    mesh = new Mesh();
    shader = new EntityShader();

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
    for (int j = 0; j < vert.size() / 3; ++j) {
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

    }
    auto indices = std::vector<unsigned int>();
    for (int i = 0; i < vert.size() / 3; ++i) {
        indices.push_back(i);
    }


    mesh->vertices(vert.data(), vert.size()).colors(colors.data(), colors.size()).indices(indices.data(),
                                                                                          indices.size());
    entities.push_back(new FPSController(renderer.getAspectRatio(),renderer.getFOV(),vec3(0),vec3(0),vec3(1.0f)));
    entities.push_back(new MeshRenderer(*mesh, *shader, vec3(0, 0, -2.0f),vec3(0),vec3(1.0f)));
    entities.push_back(new MeshRenderer(*mesh, *shader, vec3(0, 0, 2.0f),vec3(0),vec3(1.0f)));
    entities.push_back(new MeshRenderer(*mesh, *shader, vec3(2, 0, 0),vec3(0),vec3(1.0f)));
    entities.push_back(new MeshRenderer(*mesh, *shader, vec3(-2, 0, 0),vec3(0),vec3(1.0f)));
    renderer.setCamera(entities[0]->transform);

}

void Test::update() {
    for(auto e:entities)
    {
        e->update(0,*window);
    }
    if (window->isKeyDown(GLFW_KEY_0)) {
        renderer->setRenderMode(*window, Renderer::ORTHOGRAPHIC);
    }
    if (window->isKeyDown(GLFW_KEY_9)) {
        renderer->setRenderMode(*window, Renderer::PERSPECTIVE);
    }
    if(window->isKeyDown(GLFW_KEY_ESCAPE))
    {
        window->setShouldClose();
    }
}

void Test::render() {
    for (auto &e : entities) {
        e->render(*renderer);
    }
}

Test::~Test() {
    delete mesh;
    delete shader;
    delete[]entities.data();
    entities.clear();
}

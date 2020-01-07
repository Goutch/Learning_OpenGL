//
// Created by User on 18-Nov.-2019.
//

#include "Test.h"
#include "entities/MeshRenderer.h"

#include "graphics/data/Texture.h"

#include "core/Window.h"
#include "core/Renderer.h"
#include "FPSController.h"
#include "graphics/Geometry.h"
Test::Test()
        : Scene() {
}

void Test::init(Window &window, Renderer &renderer) {
    Scene::init(window,renderer);
    stone.load("../res/stone.jpg");
    shader = new EntityShader();

    auto colors = std::vector<float>();
    mesh=new Mesh();
    Geometry::makeCube(*mesh);
    for (int j = 0; j < mesh->getVertexCount(); ++j) {
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
    stone.bind();
    mesh->colors(colors.data(), colors.size());
    camera=new FPSController(renderer.getAspectRatio(), renderer.getFOV(), vec3(0), vec3(0), vec3(1.0f));
    Entity* pivot=new Entity(vec3(0),vec3(0),vec3(1));
    float range=200;
    for (int i = 0; i < 10000; ++i) {
        add(new MeshRenderer(*mesh, *shader,
                vec3((float(rand())/float((RAND_MAX)) *range)-(range/2), (float(rand())/float((RAND_MAX)) *range)-(range/2), (float(rand())/float((RAND_MAX)) *range)-(range/2)),
                vec3(float(rand())/float((RAND_MAX)) * M_PI,float(rand())/float((RAND_MAX)) * M_PI,float(rand())/float((RAND_MAX)) * M_PI),
                vec3(1.0f)));
        entities[i]->transform.parent=&(pivot->transform);
    }
    add(camera);
    add(pivot);
    renderer.setCamera(camera->transform);
}

void Test::update(float delta) {
    Scene::update(delta);
    entities[4001]->transform.rotate(0.001,vec3(0,1,0));

    if (window->isKeyDown(GLFW_KEY_0)) {
        renderer->setRenderMode(*window, Renderer::ORTHOGRAPHIC);
    }
    if (window->isKeyDown(GLFW_KEY_9)) {
        renderer->setRenderMode(*window, Renderer::PERSPECTIVE);
    }
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->setShouldClose();
    }
}



Test::~Test() {
    delete mesh;
    delete shader;
    delete camera;
    stone.unbind();
}

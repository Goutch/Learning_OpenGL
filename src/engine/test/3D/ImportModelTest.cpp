//
// Created by User on 15-Jan.-2020.
//

#include <graphics/Geometry.h>
#include "ImportModelTest.h"
#include <entities/FPSController.h>
#include <core/Renderer.h>
#include <entities/MeshRenderer.h>
#include <core/Window.h>
#include "utils/TimeUtils.h"
#include <iostream>

void ImportModelTest::init(Window &window, Renderer &renderer) {

    Scene::init(window, renderer);
    renderer.setRenderMode(window,Renderer::PERSPECTIVE);
    mesh=new Mesh();
    shader=new EntityShader();
    //Geometry::makeCube(*mesh);

    Geometry::import(*mesh,"../res/dragon.obj");

    addEntity(new MeshRenderer(*mesh,*shader));

    std::vector<float> colors=std::vector<float>();

    for (int j = 0; j <4*mesh->getVertexCount() ; ++j) {
        if(j%4==3)colors.push_back(1);
        else
            colors.push_back(float(rand() / float(RAND_MAX)));

    }

    mesh->colors(colors.data(), colors.size());
    FPSController* camera=new FPSController();
    addEntity(*camera);
    renderer.setCamera(camera->transform);

}

void ImportModelTest::update(float delta) {

    Scene::update(delta);
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->close();
    }

}

void ImportModelTest::render() {
    Scene::render();

}

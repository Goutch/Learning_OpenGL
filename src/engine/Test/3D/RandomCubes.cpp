//
// Created by User on 18-Nov.-2019.
//

#include "RandomCubes.h"
#include "entities/MeshRenderer.h"

#include "Geometry/data/Texture.h"

#include "core/Window.h"
#include "core/Renderer.h"
#include "entities/FPSController.h"
#include "Geometry/Geometry.h"

RandomCubes::RandomCubes()
        : Scene() {
}

void RandomCubes::init(Window &window, Renderer &renderer) {
    Scene::init(window,renderer);
    renderer.setRenderMode(window,Renderer::PERSPECTIVE);
    stone.load("../res/stone.jpg");

    Geometry::makeCube(mesh);
    std::vector<float> colors=std::vector<float>();

    for (int j = 0; j <4*mesh.getVertexCount() ; ++j) {
        colors.push_back(1);
    }
    mesh.colors(colors.data(), colors.size());
    camera=new FPSController();

    float range=200;
    material.shader(shader);
    material.texture(stone);
    for (int i = 0; i < 10000; ++i) {
        addEntity(new MeshRenderer(mesh,material,
                                   vec3((float(rand()) / float((RAND_MAX)) * range) - (range / 2),
                                        (float(rand()) / float((RAND_MAX)) * range) - (range / 2),
                                        (float(rand()) / float((RAND_MAX)) * range) - (range / 2)),
                                   vec3(float(rand()) / float((RAND_MAX)) * M_PI,
                                        float(rand()) / float((RAND_MAX)) * M_PI,
                                        float(rand()) / float((RAND_MAX)) * M_PI),
                                   vec3(1, 1, 1)));
    }
    addEntity(camera);

    renderer.setCamera(camera->transform);

}

void RandomCubes::update(float delta) {
    Scene::update(delta);
    if (window->isKeyDown(GLFW_KEY_ESCAPE)) {
        window->close();
    }
}



RandomCubes::~RandomCubes() {

    stone.unbind();
}

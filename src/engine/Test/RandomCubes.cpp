//
// Created by User on 18-Nov.-2019.
//

#include "RandomCubes.h"
#include "Entities/MeshRenderer.h"

#include "Data/Texture.h"

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Entities/FPSController.h"
#include "Geometry/Geometry.h"


void RandomCubes::init(Window &window, Renderer &renderer) {
    Scene::init(window,renderer);
    renderer.setRenderMode(window,Renderer::PERSPECTIVE);
    stone.load("../res/stone.jpg");

    Geometry::make_cube(mesh);
    std::vector<float> colors=std::vector<float>();

    for (int j = 0; j <4*mesh.getVertexCount() ; ++j) {
        colors.push_back(1);
    }
    mesh.colors(colors.data(), colors.size());
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
    addEntity(new FPSController(camera));
}




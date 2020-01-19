//
// Created by User on 18-Nov.-2019.
//

#include "PerformanceTest.h"
#include "Entities/MeshRenderer.h"

#include "Data/Texture.h"

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Entities/FPSController.h"
#include "Geometry/Geometry.h"


void PerformanceTest::init(Window &window, Renderer &renderer) {
    Scene::init(window,renderer);
    renderer.setRenderMode(window,Renderer::PERSPECTIVE);
    Geometry::make_cube(mesh);

    float range=100;
    for (int i = 0; i < 50000; ++i) {
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




//
// Created by User on 18-Nov.-2019.
//

#include "PerformanceTest.h"
#include "Entities/MeshRenderer.h"

#include "Data/Texture.h"

#include "Core/Window.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Entities/FPSController.h"
#include "Geometry/Geometry.h"
#include "Entities/Camera.h"
const float PI=3.1416;

void PerformanceTest::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport,renderer,window);

    Geometry::make_cube(mesh);

    float range=200;
    for (int i = 0; i < 50000; ++i) {
        addEntity(new MeshRenderer(mesh,material,
                                   vec3((float(rand()) / float((RAND_MAX)) * range) - (range / 2),
                                        (float(rand()) / float((RAND_MAX)) * range) - (range / 2),
                                        (float(rand()) / float((RAND_MAX)) * range) - (range / 2)),
                                   vec3(float(rand()) / float((RAND_MAX)) * PI,
                                        float(rand()) / float((RAND_MAX)) * PI,
                                        float(rand()) / float((RAND_MAX)) * PI),
                                   vec3(1, 1, 1)));
    }
    addEntity(new FPSController(camera->transform));
}




//
// Created by User on 15-Jan.-2020.
//

#include "Geometry/Geometry.h"
#include "ImportModelTest.h"
#include <Entities/FPSController.h>
#include <Core/Renderer.h>
#include <Entities/MeshRenderer.h>
#include "Core/Window.h"


void ImportModelTest::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    std::vector<float> colors=std::vector<float>();
    for (int j = 0; j <4*mesh.getVertexCount() ; ++j) {
        if(j%4==3)colors.push_back(1);
        else
            colors.push_back(float(rand() / float(RAND_MAX)));

    }
    mesh.colors(colors.data(), colors.size());
    addEntity(new MeshRenderer(mesh,material));
    addEntity(new FPSController(camera));
}


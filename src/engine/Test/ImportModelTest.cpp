//
// Created by User on 15-Jan.-2020.
//

#include "Geometry/Geometry.h"
#include "ImportModelTest.h"
#include <Entities/FPSController.h>
#include <Entities/MeshRenderer.h>
#include "Entities/Camera.h"
void ImportModelTest::init(Viewport &viewport, Renderer &renderer, Window &window){
    Scene::init(viewport,renderer,window);
    addEntity(new MeshRenderer(mesh,material));
    addEntity(new FPSController(camera->transform));

}


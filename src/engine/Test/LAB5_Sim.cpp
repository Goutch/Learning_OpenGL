
#include "LAB5_Sim.h"
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Spacial/FPSController.h>
#include <Entities/Spacial/Light/PointLight.h>
void LAB5_Sim::init(const Canvas &viewport, Renderer &renderer, Input &input) {
    SpacialScene::init(viewport, renderer, input);
    ambient_light=Color(0.2,0.2,0.2,1);
    addEntity(new MeshRenderer(bunny_mesh,bunny_material,vec3(0,0,0),vec3(0),vec3(5,5,5)));
    addLight(new PointLight(Color(1,1,1,1),20, vec3(1,4,4)));

    camera.transform.position(vec3(0,5,10));
    camera.transform.parent=&pivot;
}

void LAB5_Sim::update(float delta) {
    SpacialScene::update(delta);
}

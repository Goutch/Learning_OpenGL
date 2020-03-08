//
// Created by User on 05-Mar.-2020.
//

#include "Grass.h"

void Grass::init(SpacialScene &scene) {
    material = new LightMaterial(shader, scene);
    material->setColor(Color(0.6,0.85,0.1));
    SpacialEntity::init(scene);
    int ammount = 500000;
    int range = 50;

    float *data = new float[ammount * 3];
    float *normals = new float[ammount * 2];
    for (int i = 0; i < ammount; ++i) {
        data[(i * 3)] = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (range * 2))) - range;
        data[(i * 3) + 1] = 0;
        data[(i * 3) + 2] = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (range * 2))) - range;
        float rnd = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (3.1416)));
        normals[(i * 2)] = cos(rnd);
        normals[(i * 2) + 1] = sin(rnd);
    }

    vao.put(Mesh::VERTICIES, 3, data, ammount * 3, false);
    vao.put(Mesh::NORMALS, 2, normals, ammount * 2, false);
    delete data;
    delete normals;
}

void Grass::draw(const SpacialScene &scene) const {
    SpacialEntity::draw(scene);
    scene.getRenderer().draw(vao, *material, transform, Renderer::PRIMITIVE_POINTS, false);
}

void Grass::update(float delta, SpacialScene &scene) {
    SpacialEntity::update(delta, scene);


}

void Grass::onDestroy(SpacialScene &scene) {
    SpacialEntity::onDestroy(scene);
    delete material;
}

SpacialMaterial &Grass::getMaterial() {
    return *material;
}




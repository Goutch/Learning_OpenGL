//
// Created by User on 05-Mar.-2020.
//

#include "Grass.h"

void Grass::init(Scene &scene) {
    material = new LightMaterial(shader, scene);
    material->setColor(Color(.5,.7,.4,1));
    Entity::init(scene);
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

void Grass::draw(const Scene &scene) const {
    Entity::draw(scene);
    Renderer::RenderOption option;
    option.cull_faces=false;
    option.primitive_type=Renderer::PRIMITIVE_POINTS;
    scene.getRenderer().draw(vao, *material, transform, option);
}

void Grass::update(float delta, Scene &scene) {
    Entity::update(delta, scene);


}

void Grass::onDestroy(Scene &scene) {
    Entity::onDestroy(scene);
    delete material;
}

EntityMaterial &Grass::getMaterial() {
    return *material;
}




//
// Created by User on 13-Mar.-2020.
//

#include "Test.h"

void Test::init(Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    auto cam=new FPSController(*camera, vec3(0, 16, 0), vec3(0), vec3(1));
    loader.setLoaderTransform(cam->transform);
    instantiate(cam);

}

void Test::update(float delta) {
    Scene::update(delta);
    loader.update(delta);

}

void Test::render() const {
    Scene::render();
}

void Test::draw() const {
    Scene::draw();
}

Test::~Test() {

}

//
// Created by User on 05-Feb.-2020.
//

#include <API_ALL.h>

void Scene::init(Canvas &canvas, Renderer &renderer, Input &input) {
    this->canvas=&canvas;
    this->renderer=&renderer;
    this->input=&input;
    camera = new Camera();
    instantiate(camera);
}

void Scene::update(float delta) {
    if(input->isKeyDown(GLFW_KEY_F11))
    {
        renderer->screenShot(canvas->getPixelWidth(),canvas->getPixelHeight());
    }
    if(input->isKeyDown(GLFW_KEY_M)) {
        pressing_tonal_mapping_key = true;
    }
    if(pressing_tonal_mapping_key && input->isKeyReleased(GLFW_KEY_M)) {
        tonal_mapping = !tonal_mapping;
        pressing_tonal_mapping_key = false;
    }
    for (auto e:entities) {
        e->update(delta, *this);
    }
}

void Scene::draw() const {
    for (auto e:entities) {
        e->draw(*this);
    }
}

Entity& Scene::instantiate(Entity *entity) {
    entities.insert(entity);
    entity->init(*this);
}

void Scene::render() const {
    renderer->render(canvas->getFrameBuffer(), camera->getProjectionMatrix(), camera->getViewMatrix());
}

const Color &Scene::getAmbientLight() const {
    return ambient_light;
}

Camera &Scene::getCamera() const {
    return *camera;
}

Scene::~Scene() {
    for (auto e:entities) {
        e->onDestroy(*this);
        delete e;
    }
    entities.clear();
}

const std::set<Entity *> &Scene::getEntities() const {
    return entities;
}

void Scene::setCamera(Camera &camera) {
    this->camera = &camera;
}
const Canvas &Scene::getCanvas() const {
    return *canvas;
}

Renderer &Scene::getRenderer() const {
    return *renderer;
}

Input &Scene::getInput() const {
    return *input;
}

void Scene::destroy(Entity *entity) {
    entity->onDestroy(*this);
    entities.erase(entity);
    delete entity;
}

bool Scene::isTonalMapping() const {
    return tonal_mapping;
}







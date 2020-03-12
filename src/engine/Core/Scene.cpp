//
// Created by User on 05-Feb.-2020.
//

#include <API_ALL.h>

void Scene::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    this->canvas=&canvas;
    this->renderer=&renderer;
    this->input=&input;
    camera = new Camera();
    instantiate(camera);
}

void Scene::update(float delta) {
    for (auto e:entities) {
        e->update(delta, *this);
    }
}

void Scene::draw() const {
    Log::message("draw");
    int count=0;
    for (auto e:entities) {
        Log::debug("drawcall#"+std::to_string(count++));
        e->draw(*this);
    }
}

Entity& Scene::instantiate(Entity *entity) {
    entities.push_back(entity);
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
    for (unsigned int i = 0; i < entities.size(); ++i) {
        entities[i]->onDestroy(*this);
        delete entities[i];
    }
    entities.clear();
}

const std::vector<Entity *> &Scene::getEntities() const {
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
    for (auto e=entities.begin(); e != entities.end(); e++) {
        if((*e)==entity)
        {
            (*e)->onDestroy(*this);
            entities.erase(e);
            break;
        }
    }


}







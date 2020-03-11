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
    for (auto e:Entities) {
        e->update(delta, *this);
    }
    for (unsigned int i = 0; i < directional_lights.size(); ++i) {
        directional_lights[i]->calculateShadowMap(*this);
    }
}

void Scene::draw() const {
    for (auto e:Entities) {
        e->draw(*this);
    }
}

Entity& Scene::instantiate(Entity *entity) {
    Entities.push_back(entity);
    entity->init(*this);
}

void Scene::render() const {
    renderer->render(canvas->getFrameBuffer(), camera->getProjectionMatrix(), camera->getViewMatrix());
}



const std::vector<PointLight *> &Scene::getPointLights() const {
    return point_lights;
}

const Color &Scene::getAmbientLight() const {
    return ambient_light;
}

Camera &Scene::getCamera() {
    return *camera;
}

const std::vector<DirectionalLight *> &Scene::getDirectionalLights() const {
    return directional_lights;
}

Scene::~Scene() {
    for (unsigned int i = 0; i < Entities.size(); ++i) {
        Entities[i]->onDestroy(*this);
        delete Entities[i];
    }
    Entities.clear();
    directional_lights.clear();
    point_lights.clear();
}

const std::vector<Entity *> &Scene::getEntities() const {
    return Entities;
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
    for (auto e=Entities.begin();e!=Entities.end();e++) {
        if((*e)==entity)
        {
            (*e)->onDestroy(*this);
            Entities.erase(e);
            break;
        }
    }


}







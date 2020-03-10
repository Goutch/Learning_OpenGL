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
    for (auto e:spacialEntities) {
        e->update(delta, *this);
    }
    for (unsigned int i = 0; i < directional_lights.size(); ++i) {
        directional_lights[i]->calculateShadowMap(*this);
    }
}

void Scene::draw() const {
    for (auto e:spacialEntities) {
        e->draw(*this);
    }
}

Entity& Scene::instantiate(Entity *entity) {
    spacialEntities.push_back(entity);
    entity->init(*this);
}

void Scene::render() const {
    renderer->render(canvas->getFrameBuffer(), camera->getProjectionMatrix(), camera->getViewMatrix());
}

void Scene::addLight(PointLight *light) {
    point_lights.push_back(light);
    spacialEntities.push_back(light);
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

void Scene::addLight(DirectionalLight *light) {
    directional_lights.push_back(light);
    spacialEntities.push_back(light);
}

const std::vector<DirectionalLight *> &Scene::getDirectionalLights() const {
    return directional_lights;
}

Scene::~Scene() {
    for (unsigned int i = 0; i < spacialEntities.size(); ++i) {
        spacialEntities[i]->onDestroy(*this);
        delete spacialEntities[i];
    }
    spacialEntities.clear();
    directional_lights.clear();
    point_lights.clear();
}

const std::vector<Entity *> &Scene::getSpacialEntities() const {
    return spacialEntities;
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
void Scene::removeEntity(Entity *entity) {

    for (auto entityInVec : spacialEntities) {
        if (entityInVec == entity) {
            Transform *parent = entityInVec->transform.parent;

            std::list<Entity *> children;
            for (auto entityInVec2 : spacialEntities) {
                if (entityInVec2->transform.parent == &entity->transform) {
                    children.push_back(entityInVec2);
                }
            }

            for (auto child: children) {
                removeEntity(child);
            }

            bool found = false;
            for (int i = 0; i < spacialEntities.size() - 1; ++i) {
                if (spacialEntities[i] == entity) {
                    found = true;
                }

                if (found) {
                    spacialEntities[i] = spacialEntities[i + 1];
                }
            }

            delete spacialEntities[spacialEntities.size() - 1];
            spacialEntities[spacialEntities.size() - 1]= nullptr;
            spacialEntities.pop_back();
        }
    }
}

void Scene::destroy(Entity *entity) {
    removeEntity(entity);
    for (int i = 0; i < point_lights.size(); ++i) {
        if (point_lights[i]!=nullptr) {
            point_lights.erase(point_lights.begin() + i);
            break;
        }
    }
}







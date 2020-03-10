//
// Created by User on 2020-01-06.
//

#include "Entity.h"
#include <Core/Scene.h>
Entity::Entity(vec3 position, vec3 rotation, vec3 scale) {
    transform.translate(position);
    transform.rotate(quat(rotation));
    transform.scale(scale);
}

Entity::Entity() {

}

void Entity::onDestroy(Scene &scene) {
    for (auto c=children.begin();c!=children.end();c++) {
        scene.destroy(*c);
    }
}

void Entity::draw(const Scene &scene) const {}

void Entity::update(float delta, Scene &scene) {}

void Entity::init(Scene &scene) {}

const std::string &Entity::getName() const {
    return name;
}

void Entity::setName(const std::string &name) {
    Entity::name = name;
}

void Entity::addChild(Entity *child) {
    children.insert(child);
    child->transform.parent = &transform;
}

void Entity::removeChild(Entity *child) {
    children.erase(child);
}

void Entity::removeChild(std::string name) {
    for (auto c = children.begin(); c != children.end(); c++) {
        if ((*c)->getName() == name) {
            children.erase(c);
            break;
        }
    }
}

void Entity::setParent(Entity *parent) {
    parent->addChild(this);
}

std::set<Entity *> Entity::getChildren() {
    return children;
}




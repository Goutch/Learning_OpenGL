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
    if(children.find(child)==children.end())
    {
        children.insert(child);
        child->parent=this;
        child->transform.parent = &transform;
    }
}

void Entity::removeChild(Entity *child) {
    if(children.find(child)!=children.end())
    {
        children.erase(child);
        child->parent= nullptr;
        child->transform.parent = nullptr;
    }
}

void Entity::removeChild(std::string name) {
    for (auto c = children.begin(); c != children.end(); c++) {
        if ((*c)->getName() == name) {
            removeChild(*c);
            break;
        }
    }
}

void Entity::setParent(Entity *parent) {
    if(parent!= nullptr)
    {
        parent->addChild(this);
    }
    else
    {
        this->parent= nullptr;
        transform.parent= nullptr;
    }

}

std::set<Entity *> Entity::getChildren() {
    return children;
}
Entity* Entity::getParent()
{
    return parent;
}
void Entity::onDestroy(Scene &scene) {
    if(parent!= nullptr)parent->removeChild(this);
    for (auto c=children.begin();c!=children.end();c++) {
        scene.destroy(*c);
    }
}


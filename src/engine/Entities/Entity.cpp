//
// Created by User on 24-Feb.-2020.
//

#include "Entity.h"

const std::string &Entity::getName() const {
    return name;
}

Entity::~Entity() {

}

void Entity::setName(const std::string &name) {
    Entity::name = name;
}

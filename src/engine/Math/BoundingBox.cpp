//
// Created by User on 2020-03-22.
//

#include "BoundingBox.h"

BoundingBox::BoundingBox() {
    this->pos=glm::vec3(0);
    this->pos=glm::vec3(0);
}

BoundingBox::BoundingBox(glm::vec3 size) {
    this->size=size;
    this->pos=glm::vec3(0);
}

BoundingBox::BoundingBox(glm::vec3 position, glm::vec3 size) {
    this->size=size;
    this->pos=position;
}


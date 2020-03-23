#pragma once

#include "glm/glm.hpp"
class BoundingBox {
public:
    glm::vec3 pos;
    glm::vec3 size;
    BoundingBox();
    BoundingBox(glm::vec3 size);
    BoundingBox(glm::vec3 position,glm::vec3 size);
};
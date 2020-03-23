#pragma once

#include "glm/glm.hpp"
struct Plane {
    glm::vec3 normal;
    float d;
    Plane();
    Plane(glm::vec4 equation);
    void set(glm::vec4 equation);
    float distance(const glm::vec3& point) const;
};

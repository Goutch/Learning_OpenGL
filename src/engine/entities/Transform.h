#pragma once

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
class Transform {
    glm::mat4x4 transform_mattrix;
public:
    glm::mat4x4 getTransformMattrix();
    void translate(glm::vec3 pos);
    Transform();
};



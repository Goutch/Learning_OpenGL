#pragma once

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include "glm/gtx/quaternion.hpp"
class Transform {
private:
    glm::mat4 transform_mattrix=glm::mat4(1.0f);
    glm::quat local_rot=glm::quat();
public:
    glm::mat4 toMatrix();
    glm::vec3 position();
    glm::quat rotation();
    void translate(glm::vec3 translation);
    void rotate(glm::vec3 axis, float angle);
    void scale(glm::vec3 scale);
    Transform();
    Transform(glm::vec3 position);


};



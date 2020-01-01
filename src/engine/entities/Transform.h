#pragma once

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include "glm/gtx/quaternion.hpp"

class Transform {
private:
    Transform* parent;
    glm::mat4 transform_mattrix = glm::mat4(1.0f);
    glm::quat local_rot = glm::quat();
    glm::vec3 local_pos = glm::vec3();
    glm::vec3 local_scale = glm::vec3();
public:
    Transform();

    Transform(glm::vec3 position, glm::quat rotation, glm::vec3 scale,Transform* parent);

    void setParent(Transform* parent);

    glm::mat4 toMatrix();

    void translate(glm::vec3 translation);

    void rotate(glm::vec3 axis, float angle);

    void scale(glm::vec3 scale);

    glm::vec3 localPosition();

    glm::quat localRotation();

    glm::vec3 localScale();

    glm::vec3 globalPosition();

    glm::quat globalRotation();

    glm::vec3 globalScale();

    void localPosition(glm::vec3 position);

    void localRotation(glm::quat rotation);

    void localScale(glm::vec3 scale);

    void globalPosition(glm::vec3 position);

    void globalRotation(glm::quat rotation);

    void globalScale(glm::vec3 scale);


};



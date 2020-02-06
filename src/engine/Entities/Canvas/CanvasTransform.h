#pragma once


#include "glm/gtx/quaternion.hpp"
#include <glm/gtx/transform.hpp>
#include "glm/gtx/matrix_decompose.hpp"

using namespace glm;

class CanvasTransform {
    mat4 transform_matrix = glm::mat4(1.0f);
    float rot=0;
    CanvasTransform *parent = nullptr;
public:
    CanvasTransform();

    CanvasTransform(vec2 position, float rotation, vec2 scale);

    void position(vec2 position);
    void translate(vec2 translation);
    vec2 position() const;
    void scale(vec2 scale);
    vec2 scale() const;
    void rotate(float rotation);
    float rotation() const;
    mat4 getMatrix()const ;
};
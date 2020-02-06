//
// Created by User on 05-Feb.-2020.
//

#include "CanvasTransform.h"

CanvasTransform::CanvasTransform() {

}

CanvasTransform::CanvasTransform(vec2 position, float rotation, vec2 scale) {
    //todo
}

void CanvasTransform::position(vec2 position) {
    //todo
}

void CanvasTransform::translate(vec2 translation) {
    //todo
}

vec2 CanvasTransform::position() const {
    return glm::vec2();
}

void CanvasTransform::scale(vec2 scale) {
    //todo
}

vec2 CanvasTransform::scale() const{
    //todo
    return glm::vec2();
}

void CanvasTransform::rotate(float rotation) {
    //todo
}

float CanvasTransform::rotation() const{
    //todo
    return 0;
}

mat3 CanvasTransform::getMatrix()const {
    return transform_matrix;
}

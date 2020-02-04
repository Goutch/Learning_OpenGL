//
// Created by User on 04-Feb.-2020.
//

#include "Primitive.h"
#include <Geometry/VAO.h>
#include <Shaders/Material.h>
Primitive::Primitive(const VAO &vao, const Transform &transform, const Material &material) {
    this->transform = transform;
    this->vao = &vao;
    this->material = &material;
}

Primitive::Primitive(const VAO &vao, Transform transform, const Material &material, Color color) {
    this->transform = transform;
    this->color = color;
    this->material=&material;
    this->vao = &vao;
    customColor = true;
}
void Primitive::setCustomMaterialAttributes() {
    if (customColor) {
        material->shader().loadUniform("material_color", color);
    }
}



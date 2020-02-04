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
    customColor=false;
}

Primitive::Primitive(const VAO &vao, Transform transform, const Material &material, Color color) {
    this->transform = transform;

    this->material=&material;
    this->vao = &vao;
    this->color = color;
    customColor = true;
}
void Primitive::setCustomMaterialAttributes() {
    if (customColor) {
        material->shader().loadUniform("material_color", color);
    }
}



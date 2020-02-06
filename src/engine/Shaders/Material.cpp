//
// Created by User on 05-Feb.-2020.
//


#include "Material.h"
#include "Shader.h"
Material::Material() {

}
Material::Material(const Shader &shader) {
    setShader(shader);
}

Material::Material(const Shader &shader,const Color &color) {
    setShader(shader);
    setColor(color);
}
void Material::setShader(const Shader &shader) {
    this->shader=&shader;
    getUniformsLocations();
}
void Material::unbind() const {
    this->shader->unbind();
}
const Shader &Material::getShader() const {
    return *shader;
}

void Material::bind() const {
    shader->bind();
}

void Material::getUniformsLocations() {
    material_color_location=shader->uniformLocation("material_color");
}
void Material::setColor(const Color &color) {
    this->color=color;
}

const Color &Material::getColor() const {
    return color;
}




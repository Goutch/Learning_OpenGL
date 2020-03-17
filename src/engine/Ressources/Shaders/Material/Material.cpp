//
// Created by User on 05-Feb.-2020.
//


#include "Material.h"
#include "Ressources/Shaders/Shader.h"
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
    shader_initialized= false;
}
void Material::unbind() const {
    this->shader->unbind();
}
const Shader &Material::getShader() const {
    return *shader;
}

void Material::bind() const {
    if(!shader_initialized) getUniformsLocations();
    shader->bind();
    shader->loadUniform(material_color_location,color);
}

void Material::getUniformsLocations() const{
    material_color_location=shader->uniformLocation("material_color");
}
void Material::setColor(const Color &color) {
    this->color=color;
    has_transparency=color.a!=1;
}

const Color &Material::getColor() const {
    return color;
}

void Material::setTransparent(bool transparent){
    has_transparency=transparent;
};

bool Material::hasTransparency() const{
    return has_transparency;
}




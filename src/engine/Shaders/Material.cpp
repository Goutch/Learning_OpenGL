//
// Created by User on 16-Jan.-2020.
//

#include "Shaders/Material.h"
#include "Core/Scene.h"
#include "Data/Texture.h"

Material::Material() {

}

Material::Material(const Shader &shader) {
    this->shader(shader);
}

Material::Material(const Shader &shader,const Color &color) {
    this->shader(shader);
    this->color(color);

}

Material::Material(const Shader &shader,const  Texture &texture) {
    this->shader(shader);
    this->texture(texture);
}

Material::Material(const Shader &shader, const Texture &texture,const Color &color) {
    this->shader(shader);
    this->texture(texture);
    this->c = color;
}


void Material::bind(const Scene& scene) const{
    s->bind();
    s->loadUniform(material_color_location,c.data);
    if (has_texture) {
        s->loadUniform(texture_0_location, 0);
        s->loadUniform(has_texture_location, true);
        t->bind();
    } else {
        s->loadUniform(has_texture_location, false);
    }
}

void Material::unbind() const{
    s->unbind();
    if (has_texture)t->unbind();
}

Material& Material::texture(const Texture &texture) {
    t = &texture;
    has_texture = (t != nullptr);
    return *this;
}


const Texture &Material::texture() const {
    return *t;
}

Material& Material::shader(const Shader &shader) {
    s = &shader;
    this->getUniformsLocations();
    return *this;
}

const Shader &Material::shader() const {
    return *s;
}

void Material::getUniformsLocations() {
    transform_location = s->uniformLocation("transform");
    space_mat_location = s->uniformLocation("space");

    has_texture_location = s->uniformLocation("has_texture");
    texture_0_location = s->uniformLocation("texture_0");
    material_color_location=s->uniformLocation("material_color");
}

void Material::transform(const mat4 &transform) const {
    s->loadUniform(transform_location, transform);
}

void Material::space(const mat4 &space_mat) const{
    s->loadUniform(space_mat_location, space_mat);
}



Material& Material::color(const Color &color) {
    c = color;
    return *this;
}

const Color &Material::color() const {
    return c;
}









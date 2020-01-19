//
// Created by User on 16-Jan.-2020.
//

#include "Shaders/Material.h"

#include "Data/Texture.h"

Material::Material() {

}

Material::Material(Shader &shader) {
    this->shader(shader);
}

Material::Material(Shader &shader,const Color &color) {
    this->shader(shader);
    this->color(color);
}

Material::Material(Shader &shader, Texture &texture) {
    this->shader(shader);
    this->texture(texture);
}

Material::Material(Shader &shader, Texture &texture,const Color &color) {
    this->shader(shader);
    this->texture(texture);
    this->c = color;
}


void Material::bind() {
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

void Material::unbind() {
    s->unbind();
    if (has_texture)t->unbind();
}

void Material::texture(Texture &texture) {
    t = &texture;
    has_texture = (t != nullptr);
}


const Texture &Material::texture() const {
    return *t;
}

void Material::shader(Shader &shader) {
    s = &shader;
    getUniformsLocations();
}

const Shader &Material::shader() const {
    return *s;
}

void Material::getUniformsLocations() {
    transform_location = s->uniformLocation("transform");
    view_location = s->uniformLocation("view");
    projection_location = s->uniformLocation("projection");
    has_texture_location = s->uniformLocation("has_texture");
    texture_0_location = s->uniformLocation("texture_0");
    material_color_location=s->uniformLocation("material_color");
}

void Material::transform(const mat4 &transform) {
    s->loadUniform(transform_location, transform);
}

void Material::view(const mat4 &view) {
    s->loadUniform(view_location, view);
}

void Material::projection(const mat4 &projection) {
    s->loadUniform(projection_location, projection);
}

void Material::color(const Color &color) {
    c = color;
}

const Color &Material::color() const {
    return c;
}









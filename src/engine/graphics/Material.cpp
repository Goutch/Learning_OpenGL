//
// Created by User on 16-Jan.-2020.
//

#include "Material.h"

#include <graphics/data/Texture.h>

Material::Material() {

}

void Material::bind() {
    s->bind();
    if (has_texture) {
        uniform("texture_0", 0);
        uniform("has_texture", true);
        t->bind();
    } else {
        uniform("has_texture", false);
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

Material::Material(Shader &shader) {
    this->shader(shader);
}

Material::Material(Shader &shader, Texture &texture) {
    this->shader(shader);
    this->texture(texture);
}

const Texture &Material::texture() const {
    return *t;
}

void Material::shader(Shader &shader) {
    s = &shader;
}

const Shader &Material::shader() const {
    return *s;
}


void Material::uniform(std::string name, bool value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, int value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, float value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, vec2 value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, vec3 value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, vec4 value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, mat3 value) {
    s->loadUniform(name, value);
}

void Material::uniform(std::string name, mat4 value) {
    s->loadUniform(name, value);
}








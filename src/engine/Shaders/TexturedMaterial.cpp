//
// Created by User on 05-Feb.-2020.
//

#include "TexturedMaterial.h"
#include <Data/Texture.h>
#include "Shader.h"

TexturedMaterial::TexturedMaterial() {

}

TexturedMaterial::TexturedMaterial(const Shader &shader) : Material(shader) {

}

TexturedMaterial::TexturedMaterial(const Shader &shader, const Color color) : Material(shader, color) {

}

TexturedMaterial::TexturedMaterial(const Shader &shader, const Texture &texture) : Material(shader) {
    setTexture(texture);
}

TexturedMaterial::TexturedMaterial(const Shader &shader, const Color color, const Texture &texture) : Material(shader,
                                                                                                               color) {
    setTexture(texture);
}

void TexturedMaterial::setTexture(const Texture &texture) {
    this->texture = &texture;
    has_texture = (this->texture != nullptr);
}

const Texture &TexturedMaterial::getTexture() const {
    return *this->texture;
}

void TexturedMaterial::getUniformsLocations() const {
    Material::getUniformsLocations();
    has_texture_location = shader->uniformLocation("has_texture");
    texture_0_location = shader->uniformLocation("texture_0");
}

void TexturedMaterial::bind() const {
    Material::bind();
    if (has_texture) {
        shader->loadUniform(texture_0_location, 0);
        shader->loadUniform(has_texture_location, true);
        texture->bind();
    } else {
        shader->loadUniform(has_texture_location, false);
    }
}

void TexturedMaterial::unbind() const {
    Material::unbind();
    if (has_texture)texture->unbind();
}

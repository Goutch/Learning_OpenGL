//
// Created by User on 22-Nov.-2019.
//
#define GLEW_STATIC

#include "GL/glew.h"
#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const std::string &path) {
    load(path);

}

Texture::Texture() {

}

Texture::Texture(unsigned char *data, int width, int height) {
    setTexturePixelData(data, width, height,false);
}

void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture_id);
}

void Texture::unbind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1, &texture_id);
}

void Texture::load(const std::string &path) {
    unsigned char *buffer;
    stbi_set_flip_vertically_on_load(1);
    buffer = stbi_load(path.c_str(), &width, &height, &bits_per_pixel, 4);
    setTexturePixelData(buffer, width, height,false);
    if (buffer) {
        stbi_image_free(buffer);
    }
}

void Texture::setTexturePixelData(unsigned char *data, int width, int height, bool smoothed) {
    glGenTextures(1, &texture_id);
    bind();
    if (smoothed) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    unbind();
}

unsigned int Texture::getWidth() {
    return width;
}

unsigned int Texture::getHeight() {
    return height;
}



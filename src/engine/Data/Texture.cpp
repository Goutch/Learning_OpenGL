//
// Created by User on 22-Nov.-2019.
//
#define GLEW_STATIC

#include "GL/glew.h"
#include "Texture.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include "Core/Log.h"
#include <fstream>

Texture::Texture(const std::string &path) {
    glGenTextures(1, &texture_id);
    load(path);
}

Texture::Texture() {
    glGenTextures(1, &texture_id);
}

Texture::Texture(unsigned char *data, int width, int height) {
    glGenTextures(1, &texture_id);
    setTexturePixelData(data, width, height, false);
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
    free(data);
    glDeleteTextures(1, &texture_id);
}

void Texture::load(const std::string &path) {
    std::ifstream f(path.c_str());
    Log::status("Loading texture:" + path);
    if (f.good()) {
        unsigned char *buffer;
        stbi_set_flip_vertically_on_load(true);
        buffer = stbi_load(path.c_str(), &width, &height, &bits_per_pixel, 4);
        setTexturePixelData(buffer, width, height, false);
        if (buffer) {
            stbi_image_free(buffer);
        }
    } else {
        Log::error("Cant load texture:" + path);
    }

}

void Texture::setTexturePixelData(unsigned char *data, int width, int height, bool smoothed) {
    this->width=width;
    this->height=height;

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

const unsigned int Texture::getID() {
    return texture_id;
}

void Texture::save(std::string path) const {
    bind();
    auto buffer=new unsigned char[width*height*4];
    glGetTexImage(GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE,buffer);
    stbi_flip_vertically_on_write(1);
    stbi_write_png(path.c_str(),width,height,4,buffer,0);
    delete[] buffer;
    unbind();
    Log::message("ScreenShot:"+path);

}



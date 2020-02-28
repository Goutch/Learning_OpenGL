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

Texture::Texture(const std::string &path, bool flip_on_load) {
    glGenTextures(1, &texture_id);
    load(path, flip_on_load);
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

    glDeleteTextures(1, &texture_id);
}

void Texture::load(const std::string &path, bool flip_on_load) {
    std::ifstream f(path.c_str());
    Log::status("Loading getTexture:" + path);
    if (f.good()) {
        unsigned char *buffer;
        stbi_set_flip_vertically_on_load(flip_on_load);
        buffer = stbi_load(path.c_str(), &width, &height, &bits_per_pixel, 4);
        setTexturePixelData(buffer, width, height, false);
        if (buffer) {
            stbi_image_free(buffer);
        }
    } else {
        Log::error("Cant load getTexture:" + path);
    }

}

void Texture::setTexturePixelData(unsigned char *data, int width, int height, bool smoothed, Type type) {

    this->width = width;
    this->height = height;
    this->type = type;
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


    switch (type) {
        case RGBA:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            break;
        case RGB:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            break;
        case DEPTH:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, data);
            break;
    }
    unbind();
}

unsigned int Texture::getWidth() const{
    return width;
}

unsigned int Texture::getHeight()  const{
    return height;
}

const unsigned int Texture::getID()  const{
    return texture_id;
}

void Texture::save(std::string path) const {
    bind();

    stbi_flip_vertically_on_write(1);

    if (type == DEPTH) {
        //float *depth_buffer = new float[width * height];
        //glGetTexImage(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, GL_FLOAT, depth_buffer);
        //stbi_write_png(path.c_str(), width, height, 1, depth_buffer, 0);
        //delete[] depth_buffer;
        Log::warning("Screenshot not supported for depth getTexture");

    } else if (type == RGBA) {
        unsigned char *color_buffer = new unsigned char[width * height * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, color_buffer);
        stbi_write_png(path.c_str(), width, height, 4, color_buffer, 0);
        delete[] color_buffer;
        Log::message("ScreenShot:" + path);
    }
    unbind();


}





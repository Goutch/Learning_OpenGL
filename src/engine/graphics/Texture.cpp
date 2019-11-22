//
// Created by User on 22-Nov.-2019.
//
#define GLEW_STATIC
#include "glew.h"
#include "Texture.h"
#include "stb_image.h"
Texture::Texture(const std::string& path) {
    unsigned char* buffer;
    stbi_set_flip_vertically_on_load(1);
    buffer=stbi_load(path.c_str(),&width,&height,&bits_per_pixel,4);
    glGenTextures(1,&texture_id);
    bind();
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,buffer);
    unbind();
    if(buffer)
    {
        stbi_image_free(buffer);
    }
}

void Texture::bind(unsigned int slot)const  {
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D,texture_id);
}
void Texture::unbind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1,&texture_id);
}

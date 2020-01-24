
#define GLEW_STATIC

#include <GL/glew.h>
#include <Core/Log.h>

#include "Core/Window.h"
#include "FBO.h"
#include "string"
#include "stb_image_write.h"
FBO::FBO(int width,int height,FBO::Type type) {
    glGenFramebuffers(1, &fbo_id);
    this->type=type;
    setSize(width,height);

}

FBO::~FBO() {
    glDeleteFramebuffers(1, &fbo_id);
}

void FBO::setSize(int width, int height) {
    this->width=width;
    this->height=height;
    bind();
    switch (type)
    {
        case COLOR:
            texture.setTexturePixelData(nullptr,width,height);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.getID(), 0);
            if(rbos.size()!=1)
            {
                rbos.resize(1);
            }
            rbos[0].setSize(width,height,RBO::DEPTH_AND_STENCIL);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbos[0].getID());
            break;
        case DEPTH:

            texture.setTexturePixelData(nullptr,width,height,true,Texture::DEPTH);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture.getID(), 0);
            glDrawBuffer(GL_NONE);
            if(rbos.size()!=0)
            {
                rbos.resize(0);
            }
            break;
    }
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        Log::error("Framebuffer is not complete!");
    unbind();
}
void FBO::bind() const{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo_id);
}

void FBO::unbind() const{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const Texture &FBO::getTexture() const {
    return texture;
}

unsigned int FBO::getID() const {
    return fbo_id;
}

void FBO::save(std::string path) const {
    bind();
    stbi_flip_vertically_on_write(1);
    int image_size = width * height * 4;
    auto buffer = new unsigned char[image_size];
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    stbi_write_png(path.c_str(), width, height, 4, buffer, 0);
    delete[] buffer;
    Log::message("ScreenShot:" + path);

}





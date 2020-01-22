
#define GLEW_STATIC

#include <GL/glew.h>

#include "FBO.h"
FBO::FBO() {
    glGenFramebuffers(1, &fbo_id);
}

FBO::FBO(int width,int height) {
    glGenFramebuffers(1, &fbo_id);
    setSize(width,height);
}

FBO::~FBO() {
    glDeleteFramebuffers(1, &fbo_id);
}

void FBO::setSize(int width, int height) {
    bind();
    texture.setTexturePixelData(nullptr,width,height);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.getID(), 0);
    rbo.setSize(width,height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo.getID());
    unbind();
}
void FBO::bind() const{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo_id);
}

void FBO::unbind() const{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

const Texture &FBO::getTexture() {
    return texture;
}

unsigned int FBO::getID() {
    return fbo_id;
}





#define GLEW_STATIC

#include <GL/glew.h>

#include "RBO.h"

RBO::RBO() {

    glGenRenderbuffers(1, &rbo_id);
}

void RBO::setSize(int width, int height,Type type) {
    bind();
    switch (type) {
        case DEPTH_AND_STENCIL:
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
            break;
        case COLOR:
            glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, width, height);
            break;

    }
    unbind();
}

RBO::~RBO() {
    glDeleteRenderbuffers(1, &rbo_id);
}

void RBO::bind() const {
    glBindRenderbuffer(GL_RENDERBUFFER, rbo_id);
}

void RBO::unbind() const {
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

unsigned int RBO::getID() {
    return rbo_id;
}






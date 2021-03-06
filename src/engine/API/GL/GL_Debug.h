#pragma once
#define GLEW_STATIC
#include "GL/glew.h"

namespace GL_Debug{
    void init();
    void clearGLErrors();
    void printGLErrors();
    void GLAPIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                                                GLenum severity, GLsizei length,
                                                const GLchar *msg, const void *data);
}

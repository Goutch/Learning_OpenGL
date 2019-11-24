#pragma once
#define GLEW_STATIC
#include<iostream>
#include "GL/glew.h"
template<typename T>
static void printVector(const T x, const T y, const T z) {
    std::cout << "(" << x << "," << y << "," << x << ")" << std::endl;
}
static void clearGLErrors() {
    while(glGetError()!=GL_NO_ERROR);
}


static void printGLErrors()
{
    while(GLenum error=glGetError())
    {
        std::cerr<<"[OPENGL ERROR]:"<<error<<std::endl;
    }
}
template<typename T>
static void printVector(const T x, const T y) {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

static void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                                     GLenum severity, GLsizei length,
                                     const GLchar *msg, const void *data)
{
    std::string _source;
    std::string _type;
    std::string _severity;

    switch (source) {
        case GL_DEBUG_SOURCE_API:
            _source = "API";
            break;

        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            _source = "WINDOW SYSTEM";
            break;

        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            _source = "SHADER COMPILER";
            break;

        case GL_DEBUG_SOURCE_THIRD_PARTY:
            _source = "THIRD PARTY";
            break;

        case GL_DEBUG_SOURCE_APPLICATION:
            _source = "APPLICATION";
            break;

        case GL_DEBUG_SOURCE_OTHER:
            _source = "UNKNOWN";
            break;

        default:
            _source = "UNKNOWN";
            break;
    }

    switch (type) {
        case GL_DEBUG_TYPE_ERROR:
            _type = "ERROR";
            break;

        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            _type = "DEPRECATED BEHAVIOR";
            break;

        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            _type = "UDEFINED BEHAVIOR";
            break;

        case GL_DEBUG_TYPE_PORTABILITY:
            _type = "PORTABILITY";
            break;

        case GL_DEBUG_TYPE_PERFORMANCE:
            _type = "PERFORMANCE";
            break;

        case GL_DEBUG_TYPE_OTHER:
            _type = "OTHER";
            break;

        case GL_DEBUG_TYPE_MARKER:
            _type = "MARKER";
            break;

        default:
            _type = "UNKNOWN";
            break;
    }

    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:
            _severity = "HIGH";
            break;

        case GL_DEBUG_SEVERITY_MEDIUM:
            _severity = "MEDIUM";
            break;

        case GL_DEBUG_SEVERITY_LOW:
            _severity = "LOW";
            break;

        case GL_DEBUG_SEVERITY_NOTIFICATION:
            _severity = "NOTIFICATION";
            break;

        default:
            _severity = "UNKNOWN";
            break;
    }
    if(severity!=GL_DEBUG_SEVERITY_NOTIFICATION)
    printf("[OPENGL ERROR]:ID:%d \n TYPE:%s \n SEVERITY: %s \n SOURCE: %s \n MESSAGE: %s\n",
           id, _type.c_str(), _severity.c_str(), _source.c_str(), msg);
}
static void initDebug()
{
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(GLDebugMessageCallback, NULL);
}


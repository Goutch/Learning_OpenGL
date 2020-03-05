//
// Created by User on 26-Feb.-2020.
//

#include "GL_API.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <Core/Log.h>
#include "GL_Debug.h"
#include <GLFW/glfw3.h>
void GL_API::init() {

    if(glewInit() == GLEW_OK){
        Log::status("Initialized GLEW");

        std::string version = (char *) glGetString(GL_VERSION);
        Log::message("OPENGL Version " + version);
        //enable textures
        glEnable(GL_TEXTURE_2D);
        //enable cull face
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        //enable depth Scenes
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        //enable transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //antializing
        //glEnable(GL_MULTISAMPLE);
    }
    Log::error("failed to initialize GLEW");
    GL_Debug::init();
}

GLFWwindow *GL_API::createWindow(std::string title, int width, int height) {
    GLFWwindow* window;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    width = width;
    height = height;
    Log::status("Opening window...");
    if (glfwInit()) {
        Log::status("Initialized GLFW");

        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(window);
        Log::status("window opened");
    }
    Log::error("failed to initialize GLFW");
    init();
    glfwSwapInterval(1);
    return window;

}

void GL_API::terminate() {
    GL_Debug::printGLErrors();
}

GL_API::~GL_API() {
    terminate();
}



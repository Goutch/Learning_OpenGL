//
// Created by User on 18-Nov.-2019.
//
#define GLEW_STATIC

#include <GL/glew.h>
#include "Scene.h"
#include <iostream>
#include <utils/Timer.h>
#include "Window.h"
#include "Engine.h"
#include "Renderer.h"
#include "../../Debug.h"


Engine::Engine() {
    window = new Window();
    if (window->open("WINDOW", 900, 600)) {
        glewInit() == GLEW_OK ?
        std::cout << "Initialized GLEW" << std::endl :
        std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;
        std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;

        initDebug();
        glEnable(GL_TEXTURE_2D);
        //enable cull face
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        //enable depth Test
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        //enable transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}

void Engine::start(Scene &scene) {
    if(glewInit() == GLEW_OK)
    {
        Renderer renderer = Renderer(*window, Renderer::ORTHOGRAPHIC);
        std::cout << "Initializing scene.." << std::endl;
        scene.init(*window, renderer);


        double delta_time=0;
        Timer t;
        std::cout << "Starting main loop.." << std::endl;
        while (!window->shouldClose()) {
            t.reset();
            printFPS();
            scene.update(delta_time);
            scene.render();
            renderer.render();
            window->swapBuffer();
            window->getInputs();
            delta_time= t.ms();
        }
    }
    printGLErrors();
}

Engine::~Engine() {

}

void Engine::printFPS() {
    fps++;
    if(last_fps_print<std::time(0)-1)
    {
        std::cout<<"fps:"<<fps<<std::endl;
        fps=0;
        last_fps_print=std::time(0);
    }
}






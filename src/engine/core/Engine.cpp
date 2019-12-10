//
// Created by User on 18-Nov.-2019.
//
#define GLEW_STATIC
#include <GL/glew.h>
#include "Game.h"
#include <iostream>
#include "Window.h"
#include "Engine.h"
#include "Renderer.h"
#include "../../Debug.h"


Engine::Engine() {

}
void Engine::start(Game &game) {
    Window window=Window();
    if (window.open("WINDOW",900, 600)) {
        glewInit() == GLEW_OK ?
        std::cout << "Initialized GLEW" << std::endl :
        std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;
        std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;

        initDebug();
        glEnable(GL_TEXTURE_2D);
        glCullFace(GL_BACK);
        //enable depth test
        //glEnable(GL_DEPTH_TEST);
        //glDepthMask(GL_FALSE);
        //glDepthFunc(GL_LESS);
        //enable transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

        Renderer renderer=Renderer(window,Renderer::ORTHOGRAPHIC);
        std::cout << "starting game.." << std::endl;
        game.init();
        while (!window.shouldClose()) {
            game.update(window);
            game.render(renderer);
            renderer.render();
            window.swapBuffer();
            window.getInputs();
        }
    }
    printGLErrors();
}

Engine::~Engine() {

}





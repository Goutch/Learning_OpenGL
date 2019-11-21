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
Engine::Engine() {

}
void Engine::start(Game &game) {
    Window window=Window();

    if (window.open("WINDOW",900, 600)) {
        glewInit() == GLEW_OK ?
        std::cout << "Initialized GLEW" << std::endl :
        std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;
        std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;
    }
    Renderer renderer=Renderer();
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

Engine::~Engine() {

}



//
// Created by User on 18-Nov.-2019.
//
#define GLEW_STATIC

#include <GL/glew.h>
#include <iostream>
#include "../graphics/DefaultRenderer.h"
#include "Window.h"

#include "Engine.h"
Engine::Engine() {

}
void Engine::start(Game &game) {
    Window window=Window("WINDOW",900, 600);

    if (window.open()) {
        glewInit() == GLEW_OK ?
        std::cout << "Initialized GLEW" << std::endl :
        std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;
        std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;
    }
    Renderer* renderer= new DefaultRenderer();
    game.init();
    while (!window.shouldClose()) {
        game.update(window);
        game.render(*renderer);
        renderer->render();
        window.swapBuffer();
        window.getInputs();
    }
    delete renderer;
}

Engine::~Engine() {

}



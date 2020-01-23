//
// Created by User on 18-Nov.-2019.
//
#define GLEW_STATIC

#include <GL/glew.h>
#include "Scene.h"
#include "Utils/Timer.h"
#include "Log.h"
#include "Window.h"
#include "Engine.h"
#include "Renderer.h"
#include "Debug.h"


Engine::Engine() {
    Log::logLevel(Log::DEBUG);
    window = new Window();
    if (window->open("WINDOW", 1000, 675)) {

        glewInit() == GLEW_OK ?
        Log::status("Initialized GLEW") :
        Log::error("failed to initialize GLEW");

        std::string version = (char *) glGetString(GL_VERSION);
        Log::message("OPENGL Version " + version);

        initDebug();
        //enable textures
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
    if (glewInit() == GLEW_OK) {
        Renderer renderer = Renderer(*window);
        Log::status("Initializing scene..");
        scene.init(*window, renderer);
        Log::status("Initialized scene");

        double delta_time = 0;
        Timer t;
        window->getInputs();
        Log::status("Starting main loop..");
        while (!window->shouldClose()) {
            window->getInputs();
            t.reset();
            printFPS();
            scene.update(delta_time);
            scene.render();
            renderer.render(scene);
            window->swapBuffer();
            window->getInputs();
            delta_time = t.ms();
        }
    }
    printGLErrors();
}

Engine::~Engine() {

}

void Engine::printFPS() {
    fps++;
    if (last_fps_print < std::time(0) - 1) {
        Log::debug("fps:" + std::to_string(fps));
        fps = 0;
        last_fps_print = std::time(0);
    }
}






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
#include "Core/Rendering/BatchRenderer.h"
#include "Core/Rendering/SimpleRenderer.h"
#include "Debug.h"
#include "Core/Viewport.h"
#include <Entities/Camera.h>

Engine::Engine() {
    Log::logLevel(Log::DEBUG);
    window = new Window();
    if (window->open("WINDOW", 1000, 700)) {
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
        Renderer* renderer =new SimpleRenderer();
        Log::status("Initializing scene..");
        Viewport viewport=Viewport(*window);
        scene.init(viewport,*renderer,*window);
        Log::status("Initialized scene");
        double delta_time = 0;
        Timer t;
        window->pollEvents();
        Log::status("Starting main loop..");
        while (!window->shouldClose()){
            window->pollEvents();
            t.reset();
            printFPS();
            scene.update((float)delta_time);
            scene.prepareRender();
            scene.render();
            renderer->draw(viewport.getRenderSpace(),viewport.getShader(),viewport.getFrameBuffer().getTexture());
            window->swapBuffer();
            delta_time = t.ms();
        }
        Log::status("Cleaning up..");
        scene.destroy();
        delete renderer;
    }
    printGLErrors();
}

Engine::~Engine() {
    delete window;
}

void Engine::printFPS() {
    fps++;
    if (last_fps_print < std::time(0) - 1) {
        Log::debug("fps:" + std::to_string(fps));
        fps = 0;
        last_fps_print = std::time(0);
    }
}






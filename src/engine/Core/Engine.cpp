
#include "Engine.h"
#include <API/GL/GL_API.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "Scene.h"
#include "Utils/Timer.h"
#include "Window.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Core/Rendering/SimpleRenderer.h"
#include <type_traits>
#include "Core/Canvas.h"
#include "Log.h"

Engine::Engine() {
    Log::logLevel(Log::DEBUG);
    graphics = new GL_API();
    window = new Window(graphics->createWindow("WINDOW", 1000, 700));
    initImgui();
    Renderer *renderer = new SimpleRenderer();
    canvas = new Canvas(*window, renderer->DEFAULT_CANVAS_SHADER);
}

void Engine::start() {
    Log::status("Initializing scene..");
    scene->init(*canvas, *renderer, *window);
    Log::status("Initialized scene");

    double delta_time = 0;
    Timer delta_time_timer;

    Log::status("Starting main loop..");
    while (!window->shouldClose()) {

        window->pollEvents();
        scene->update((float) delta_time);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        scene->draw();
        scene->render();
        renderer->renderOnMainBuffer(*canvas);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window->swapBuffer();

        delta_time = delta_time_timer.ms();
        delta_time_timer.reset();
        printFPS();
    }
    Log::status("Cleaning up..");
    delete scene;
}

Engine::~Engine() {
    delete canvas;
    delete renderer;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    graphics->terminate();
    delete graphics;
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

void Engine::initImgui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(&window->getHandle(), true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}











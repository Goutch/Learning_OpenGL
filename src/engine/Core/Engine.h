#pragma once

class Scene;
class Window;
class Canvas;
class Renderer;
class Input;
#include <ctime>
#include <API/API.h>
#include <Scenes/Editor/Editor.h>
#include "Log.h"
class Engine {
private:

    Window* window=nullptr;
    Input* input=nullptr;
    API* graphics=nullptr;
    Scene* scene=nullptr;
    Canvas* canvas=nullptr;
    Renderer* renderer=nullptr;
    std::time_t last_fps_print=std::time(0);
    bool imGuiEnabled=true;
    unsigned int fps=0;
public:
    Engine();
    ~Engine();
    void initImgui();
    template<class T>
    void runInEditor(){

        static_assert(std::is_base_of<Scene, T>::value, "template argument must be a Scene");
        if (scene) {
            delete scene;
        }
        scene = new Editor(new T());
        Log::status("Initializing scene..");
        scene->init(*canvas, *renderer, *input);
        Log::status("Initialized scene");
    }
    template<class T>
    void run(){
        static_assert(std::is_base_of<Scene, T>::value, "template argument must be a Scene");
        if (scene) {
            delete scene;
        }
        scene = new T();
        Log::status("Initializing scene..");
        scene->init(*canvas, *renderer, *input);
        Log::status("Initialized scene");
    }

private:
    void start();
    void printFPS();
    void drawSceneSelector();
};


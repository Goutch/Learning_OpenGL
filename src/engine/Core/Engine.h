#pragma once

class Scene;
class Window;
class Canvas;
class Renderer;
#include <ctime>
#include <API/API.h>
class Engine {
private:
    Window* window=nullptr;
    API* graphics=nullptr;
    Scene* scene=nullptr;
    Canvas* canvas=nullptr;
    Renderer* renderer=nullptr;
    std::time_t last_fps_print=std::time(0);
    unsigned int fps=0;
public:
    Engine();
    ~Engine();
    void initImgui();

    template<class T>
    void run(){
        static_assert(std::is_base_of<Scene, T>::value, "template argument must be a Scene");
        if (scene) {
            delete scene;
        }
        scene = new T();
        start();
    }

private:
    void start();
    void printFPS();
};


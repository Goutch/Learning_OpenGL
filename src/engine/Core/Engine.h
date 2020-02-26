#pragma once

class Scene;
class Window;

#include <ctime>
#include <API/API.h>
class Engine {
private:
    Window* window;
    API* graphics;
    unsigned int fps=0;
    std::time_t last_fps_print=std::time(0);
    void printFPS();
public:
    Engine();
    ~Engine();
    void initImgui();
    void initGlew();
    void start(Scene& scene);
};


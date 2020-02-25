#pragma once

class Scene;
class Window;

#include <ctime>
class Engine {
private:
    Window* window;
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


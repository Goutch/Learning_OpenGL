#pragma once

class Scene;
class Window;

#include <ctime>
class Engine {
private:
    Window* window;
    unsigned int fps;
    std::time_t last_fps_print=std::time(0);
    void printFPS();
public:
    Engine();
    ~Engine();
    void start(Scene& scene);
};


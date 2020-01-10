#pragma once

class Scene;
class Window;
class Engine {
private:
    Window* window;
public:
    Engine();
    ~Engine();
    void start(Scene& scene);
};


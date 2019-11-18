
#pragma once
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int sizeX,int sizeY);
    ~Window();
    bool open();
    void close();
    bool shouldClose();
    void swapBuffer();
    void getInputs();
    bool isKeyDown(unsigned int keycode);
    void getMousePosition(double &x, double &y);
    void showCursor(bool showCursor);
private:
    GLFWwindow* window;
    int sizeX=600, sizeY=400;

};

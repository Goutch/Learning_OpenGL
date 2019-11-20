
#pragma once
#include <GLFW/glfw3.h>
#include<string>
class Window
{
public:
    Window(std::string title,int sizeX,int sizeY);
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
    std::string title;
    int sizeX=600, sizeY=400;

};

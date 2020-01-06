
#pragma once
#include <GLFW/glfw3.h>
#include<string>
class Window
{
private:
    GLFWwindow* window;
    std::string title;
    int sizeX=600, sizeY=400;
    bool cursor_shown=true;
    void close();
public:
    Window();
    ~Window();
    bool open(std::string title,int sizeX,int sizeY);
    bool shouldClose();
    void setShouldClose();
    void swapBuffer();
    void getInputs();
    bool isKeyDown(unsigned int keycode);
    void getMousePosition(double &x, double &y);
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    int getWidth();
    int getHeight();


};

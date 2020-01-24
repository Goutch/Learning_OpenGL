#pragma once
#include <GLFW/glfw3.h>
#include<string>
#include "list"
class WindowSizeListener;
class Window
{
private:
    static std::list<WindowSizeListener*> sizeListeners;
    GLFWwindow* window;
    int width=600, height=400;
    bool cursor_shown=true;
public:
    Window();
    ~Window();
    bool open(std::string title, int width, int height);
    bool shouldClose();
    void close();
    void swapBuffer();
    void getInputs();
    bool isKeyDown(unsigned int keycode);
    void getMousePosition(double &x, double &y);
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    int getWidth();
    int getHeight();
    void subscribeSizeChange(WindowSizeListener& l);
    void unsubscribeSizeChange(WindowSizeListener& l);
    static void windowSizeCallback(GLFWwindow* window, int width, int height);
};
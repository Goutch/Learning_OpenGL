#pragma once
#include <GLFW/glfw3.h>
#include<string>
#include "list"
class ViewportResizeListener;
class Window
{
private:
    static std::list<ViewportResizeListener*> sizeListeners;
    GLFWwindow* window;
    int width=600, height=400;
    bool cursor_shown=true;
public:
    Window();
    ~Window();
    bool open(std::string title, int width, int height);
    bool shouldClose()const;
    void close();
    void swapBuffer()const;
    void getInputs()const;
    bool isKeyDown(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    int getWidth();
    int getHeight();
    void subscribeSizeChange(ViewportResizeListener& l);
    void unsubscribeSizeChange(ViewportResizeListener& l);
    static void windowSizeCallback(GLFWwindow* window, int width, int height);
};
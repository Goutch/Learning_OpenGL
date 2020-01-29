#pragma once
class GLFWwindow;
#include<string>
#include "list"
class WindowResizeListener;
class Window
{
private:
    static std::list<WindowResizeListener*> sizeListeners;
    GLFWwindow* window;
    mutable int width=600;
    mutable int height=400;
    bool cursor_shown=true;
public:
    Window();
    ~Window();
    bool open(std::string title, int width, int height);
    bool shouldClose()const;
    void close();
    void swapBuffer()const;
    void pollEvents()const;
    bool isKeyDown(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    int getWidth()const;
    int getHeight()const;
    void subscribeSizeChange( WindowResizeListener& l) const;
    void unsubscribeSizeChange(WindowResizeListener& l) const;
    static void windowSizeCallback(GLFWwindow* window, int width, int height);
};
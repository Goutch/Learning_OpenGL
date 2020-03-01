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

public:
    Window(GLFWwindow* window);
    ~Window();

    bool shouldClose()const;
    void close();
    void swapBuffer()const;
    void pollEvents()const;

    int getWidth()const;
    int getHeight()const;
    GLFWwindow& getHandle();
    void subscribeSizeChange( WindowResizeListener& l) const;
    void unsubscribeSizeChange(WindowResizeListener& l) const;

    static void windowSizeCallback(GLFWwindow* window, int width, int height);
};
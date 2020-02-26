#pragma once
class GLFWwindow;
#include<string>
#include "list"
class WindowResizeListener;
class KeyPressListener;
class Window
{
private:
    static std::list<WindowResizeListener*> sizeListeners;
    static std::list<KeyPressListener*> keyboardListeners;
    GLFWwindow* window;
    mutable int width=600;
    mutable int height=400;
    bool cursor_shown=true;
public:
    Window(GLFWwindow* window);
    ~Window();

    bool shouldClose()const;
    void close();
    void swapBuffer()const;
    void pollEvents()const;
    bool isKeyDown(unsigned int keycode)const;
    bool isKeyPressed(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    int getWidth()const;
    int getHeight()const;
    GLFWwindow& getHandle();
    void subscribeSizeChange( WindowResizeListener& l) const;
    void unsubscribeSizeChange(WindowResizeListener& l) const;
    void subscribeKeyPress(KeyPressListener& l) const;
    void unsubscribeKeyPress(KeyPressListener& l) const;
    static void windowSizeCallback(GLFWwindow* window, int width, int height);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

};
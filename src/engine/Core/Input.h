#pragma once

#include <GLFW/glfw3.h>
#include <list>
class KeyPressListener;
class Input {
public:
    enum CURSOR{
        HAND=GLFW_HAND_CURSOR,
        ARROW=GLFW_ARROW_CURSOR,
        IBEAM=GLFW_IBEAM_CURSOR,

    };
private:
    static std::list<KeyPressListener*> keyboardListeners;
    GLFWwindow *window;
    GLFWcursor *cursor;

    bool cursor_shown=true;
public:
    explicit Input(GLFWwindow *window);
    ~Input();
    bool isKeyDown(unsigned int keycode)const;
    bool isKeyPressed(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void subscribeKeyPress(KeyPressListener& l) const;
    void unsubscribeKeyPress(KeyPressListener& l) const;

};

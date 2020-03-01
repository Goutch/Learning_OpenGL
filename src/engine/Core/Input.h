#pragma once

#include <GLFW/glfw3.h>
#include <list>
class KeyPressListener;
class Input {
public:
    enum CursorImage{
        HAND=GLFW_HAND_CURSOR,
        ARROW=GLFW_ARROW_CURSOR,
        IBEAM=GLFW_IBEAM_CURSOR,
        CROSSHAIR=GLFW_CROSSHAIR_CURSOR,
        HRESIZE=GLFW_HRESIZE_CURSOR,
        VRESIZE=GLFW_VRESIZE_CURSOR,
    };
private:
    static std::list<KeyPressListener*> keyboardListeners;
    GLFWwindow *window;
    GLFWcursor *arrow_cursor;
    GLFWcursor *hand_cursor;
    GLFWcursor *i_beam_cursor;
    GLFWcursor *v_resize_cursor;
    GLFWcursor *h_resize_cursor;
    GLFWcursor *crosshair_cursor;

    bool cursor_shown=true;
public:
    explicit Input(GLFWwindow *window);
    ~Input();
    bool isKeyDown(unsigned int keycode)const;
    bool isKeyPressed(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    bool getMouseButtonPressed(unsigned int button) const;
    bool getMouseButtonReleased(unsigned int button) const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void subscribeKeyPress(KeyPressListener& l) const;
    void unsubscribeKeyPress(KeyPressListener& l) const;
    void setCursor(CursorImage image);
};

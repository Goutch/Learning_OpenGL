#pragma once

#include <GLFW/glfw3.h>
#include <list>
class KeyListener;
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
    static std::list<KeyListener*> keyboardListeners;
    GLFWwindow *window;
    GLFWcursor *arrow_cursor;
    GLFWcursor *hand_cursor;
    GLFWcursor *i_beam_cursor;
    GLFWcursor *v_resize_cursor;
    GLFWcursor *h_resize_cursor;
    GLFWcursor *crosshair_cursor;

    bool cursor_shown=true;
public:
    explicit Input(GLFWwindow &window);
    ~Input();
    bool isKeyDown(unsigned int keycode)const;
    bool isKeyReleased(unsigned int keycode)const;
    void getMousePosition(double &x, double &y)const;
    bool getMouseButtonPressed(int button) const;
    bool getMouseButtonReleased(int button) const;
    void showCursor(bool showCursor);
    void setMousePosition(double x,double y);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void subscribeKey(KeyListener& l) const;
    void unsubscribeKey(KeyListener& l) const;
    void setCursor(CursorImage image);
};

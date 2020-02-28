//
// Created by User on 28-Feb.-2020.
//

#include "Input.h"
#include <Events/KeyPressListener.h>
std::list<KeyPressListener *> Input::keyboardListeners = std::list<KeyPressListener *>();
Input::Input(GLFWwindow *window) {
    this->window=window;
    GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    glfwSetCursor(window, cursor);
    glfwSetKeyCallback(window, Input::keyCallback);
}

Input::~Input() {
    glfwDestroyCursor(cursor);
}


void Input::setMousePosition(double x, double y) {
    glfwSetCursorPos(window, x, y);
}
bool Input::isKeyDown(unsigned int keycode) const {
    int state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS;
}

bool Input::isKeyPressed(unsigned int keycode) const {
    int state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS;
}

void Input::getMousePosition(double &x, double &y) const {
    glfwGetCursorPos(window, &x, &y);
}

void Input::showCursor(bool showCursor) {
    if (showCursor != cursor_shown) {
        if (!showCursor)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

        cursor_shown = showCursor;
    }

}
void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action = GLFW_PRESS) {
        for (auto l:keyboardListeners) {
            l->onKeyPress(static_cast<unsigned char>(key));
        }
    } else if (action == GLFW_RELEASE) {
        //idk do somehting
    }
}

void Input::subscribeKeyPress(KeyPressListener &l) const {
    keyboardListeners.push_back(&l);
}

void Input::unsubscribeKeyPress(KeyPressListener &l) const {
    keyboardListeners.remove(&l);
}

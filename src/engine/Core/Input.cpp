//
// Created by User on 28-Feb.-2020.
//

#include "Input.h"
#include <Events/KeyPressListener.h>

std::list<KeyListener *> Input::keyboardListeners = std::list<KeyListener *>();

Input::Input(GLFWwindow *window) {
    this->window = window;
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
   //arrow_cursor = glfwCreateStandardCursor(ARROW);
   //i_beam_cursor = glfwCreateStandardCursor(IBEAM);
   //hand_cursor = glfwCreateStandardCursor(HAND);
   //v_resize_cursor = glfwCreateStandardCursor(HRESIZE);
   //h_resize_cursor = glfwCreateStandardCursor(VRESIZE);
   //crosshair_cursor = glfwCreateStandardCursor(CROSSHAIR);
   //setCursor(HAND);
   // glfwSetCursor(window,hand_cursor);
    glfwSetKeyCallback(window, Input::keyCallback);
}

Input::~Input() {
   // glfwDestroyCursor(arrow_cursor);
   // glfwDestroyCursor(hand_cursor);
   // glfwDestroyCursor(i_beam_cursor);
   // glfwDestroyCursor(h_resize_cursor);
   // glfwDestroyCursor(v_resize_cursor);
   // glfwDestroyCursor(crosshair_cursor);

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
    if (action == GLFW_PRESS) {
        for (auto l:keyboardListeners) {
            l->onKeyPress(key);
        }
    } else if (action == GLFW_RELEASE) {
        for (auto l:keyboardListeners) {
            l->onKeyReleased(key);
        }
    }
}

void Input::subscribeKey(KeyListener &l) const {
    keyboardListeners.push_back(&l);
}

void Input::unsubscribeKey(KeyListener &l) const {
    keyboardListeners.remove(&l);
}

void Input::setCursor(Input::CursorImage image) {
    switch (image) {
        case HAND:
            glfwSetCursor(window, hand_cursor);
            break;
        case ARROW:
            glfwSetCursor(window, arrow_cursor);
            break;
        case IBEAM:
            glfwSetCursor(window, i_beam_cursor);
            break;
        case CROSSHAIR:
            glfwSetCursor(window, crosshair_cursor);
            break;
        case HRESIZE:
            glfwSetCursor(window, h_resize_cursor);
            break;
        case VRESIZE:
            glfwSetCursor(window, v_resize_cursor);
            break;
    }
}

bool Input::getMouseButtonPressed(int button) const {
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

bool Input::getMouseButtonReleased(int button) const {
    return glfwGetMouseButton(window, button) == GLFW_RELEASE;
}

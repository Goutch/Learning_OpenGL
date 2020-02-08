#include "Window.h"
#include "Debug/Log.h"
#include "Events/WindowResizeListener.h"
#include <GLFW/glfw3.h>
#include <Events/KeyPressListener.h>

std::list<WindowResizeListener *> Window::sizeListeners = std::list<WindowResizeListener *>();
std::list<KeyPressListener *> Window::keyboardListeners = std::list<KeyPressListener *>();

Window::Window() {

}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
    Log::status("Terminated GLFW");
}

bool Window::open(std::string title, int width, int height) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    width = width;
    height = height;
    Log::status("Opening window...");
    if (glfwInit()) {
        Log::status("Initialized GLFW");

        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, Window::windowSizeCallback);
        glfwSetKeyCallback(window, Window::keyCallback);
        //desactivate vsych
        //glfwSwapInterval(0);
        Log::status("window opened");
        return true;
    }

    Log::error("failed to initialize GLFW");
    return false;
}

void Window::setMousePosition(double x, double y) {
    glfwSetCursorPos(window, x, y);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::swapBuffer() const {
    glfwSwapBuffers(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}

bool Window::isKeyDown(unsigned int keycode) const {
    int state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS;
}

bool Window::isKeyPressed(unsigned int keycode) const {
    int state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS;
}

void Window::getMousePosition(double &x, double &y) const {
    glfwGetCursorPos(window, &x, &y);
}

void Window::showCursor(bool showCursor) {
    if (showCursor != cursor_shown) {
        if (!showCursor)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

        cursor_shown = showCursor;
    }

}

int Window::getWidth() const {
    glfwGetFramebufferSize(window, &width, &height);
    return width;
}

int Window::getHeight() const {
    glfwGetFramebufferSize(window, &width, &height);
    return height;
}

void Window::close() {

    glfwSetWindowShouldClose(window, true);
}

void Window::windowSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    for (auto l:sizeListeners) {
        l->onWindowSizeChange(width, height);
    }
}

void Window::subscribeSizeChange(WindowResizeListener &l) const {
    sizeListeners.push_back(&l);
}

void Window::unsubscribeSizeChange(WindowResizeListener &l) const {
    sizeListeners.remove(&l);
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action = GLFW_PRESS) {
        for (auto l:keyboardListeners) {
            l->onKeyPress(static_cast<unsigned char>(key));
        }
    } else if (action == GLFW_RELEASE) {
        //idk do somehting
    }
}

void Window::subscribeKeyPress(KeyPressListener &l) const {
    keyboardListeners.push_back(&l);
}

void Window::unsubscribeKeyPress(KeyPressListener &l) const {
    keyboardListeners.remove(&l);
}






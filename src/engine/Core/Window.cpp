#include "Window.h"
#include "Log.h"
#include "Events/WindowResizeListener.h"
#include <GLFW/glfw3.h>
std::list<WindowResizeListener *> Window::sizeListeners = std::list<WindowResizeListener *>();


Window::Window(GLFWwindow* window) {
    this->window=window;
    glfwSetFramebufferSizeCallback(window, Window::windowSizeCallback);

}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
    Log::status("Terminated GLFW");
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


GLFWwindow &Window::getHandle() {
    return *window;
}






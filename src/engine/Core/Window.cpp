#include "Window.h"
#include <iostream>

Window::Window() {

}
Window::~Window()
{
    glfwTerminate();
    std::cout << "Terminated GLFW" << std::endl;
}

bool Window::open(std::string title, int width, int height)
{

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    width=width;
    height=height;
    std::cout <<"Opening window..." << std::endl;
    if (glfwInit())
    {
        std::cout <<"Initialized GLFW" << std::endl;
        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, Window::windowSizeCallback);
        //desactivate vsych
        //glfwSwapInterval(0);
        return true;
    }

    std::cerr << "FAILED:Initialized GLFW"<<std::endl;
    return false;
}
void Window::setMousePosition(double x, double y) {
    glfwSetCursorPos(window,x,y);
}
bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}
void Window::swapBuffer()
{
    glfwSwapBuffers(window);
}
void Window::getInputs()
{
    glfwPollEvents();
}

bool Window::isKeyDown(unsigned int keycode) {
    int state=glfwGetKey(window,keycode);
    return state == GLFW_PRESS;
}

void Window::getMousePosition(double& x,double& y)
{
    glfwGetCursorPos(window, &x, &y);
}

void Window::showCursor(bool showCursor) {
    if(showCursor!=cursor_shown)
    {
        if(!showCursor)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

        cursor_shown=showCursor;
    }

}
int Window::getWidth() {
    glfwGetFramebufferSize(window,&width,&height);
    return width;
}
int Window::getHeight()  {
    glfwGetFramebufferSize(window,&width,&height);
    return height;
}

void Window::close() {
    std::cout <<"Closing window..." << std::endl;
    glfwSetWindowShouldClose(window, true);
}

void Window::windowSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
}




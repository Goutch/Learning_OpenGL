#include "Window.h"
#include "Log.h"
#include "Events/WindowSizeListener.h"

std::list<WindowSizeListener*> Window::sizeListeners=std::list<WindowSizeListener*>();
Window::Window() {

}
Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
    Log::status("Terminated GLFW");
}

bool Window::open(std::string title, int width, int height)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    width=width;
    height=height;
    Log::status("Opening window...");
    if (glfwInit())
    {
        Log::status("Initialized GLFW");

        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, Window::windowSizeCallback);
        //desactivate vsych
        //glfwSwapInterval(0);
        Log::status("window opened");
        return true;
    }

    Log::error("failed to initialize GLFW");
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
    Log::status("Closing window..." );
    glfwSetWindowShouldClose(window, true);
}

void Window::windowSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
    for (auto l:sizeListeners) {
        l->onWindowSizeChange(width,height);
    }
}

void Window::subscribeSizeChange(WindowSizeListener &l) {
    sizeListeners.push_back(&l);
}

void Window::unsubscribeSizeChange(WindowSizeListener &l) {
    sizeListeners.remove(&l);
}




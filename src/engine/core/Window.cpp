
#include "Window.h"
#include <iostream>

Window::Window(std::string title, int sizeX, int sizeY) {
    this->title=title;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}
Window::~Window()
{
	close();
}

bool Window::open()
{
    std::cout <<"Opening window..." << std::endl;
	if (glfwInit())
	{
		std::cout <<"Initialized GLFW" << std::endl;
		window = glfwCreateWindow(sizeX, sizeY, title.c_str(), NULL, NULL);
		if (!window)
		{
			close();
		}
		
		glfwMakeContextCurrent(window);
		return true;
	}
	std::cerr << "FAILED:Initialized GLFW"<<std::endl;
	return false;
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
void Window::close()
{
    std::cout <<"Closing window..." << std::endl;
	glfwSetWindowShouldClose(window, true);
	glfwTerminate();
	std::cout << "Terminated GLFW" << std::endl;
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
    if(!showCursor)
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}








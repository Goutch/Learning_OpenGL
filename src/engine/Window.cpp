
#include "Window.h"
#include <iostream>

Window::Window(int sizeX, int sizeY)
{
	Window::sizeX = sizeX;
	Window::sizeY = sizeY;
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
		window = glfwCreateWindow(sizeX, sizeY, "Hello World", NULL, NULL);
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
void Window::pollEvents()
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







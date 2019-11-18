#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include "engine/Window.h"
#include "engine/shaders/ShaderProgram.h"
#include "engine/graphics/VAO.h"
int main(void)
{
	Window* window = new Window(900, 600);
	if (window->open())
	{
    	glewInit() == GLEW_OK ? std::cout << "Initialized GLEW" << std::endl : std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;
		std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;
		/* Loop until the user closes the window */

		//SHADER
		ShaderProgram* shader = new ShaderProgram("../src/BaseVertex.glsl","../src/BaseFragment.glsl");

		//VAO

		float vertices[8] = {
			-0.5f,-0.5f,
			-0.5f,0.5f,
			0.5,0.5f,
			0.5f,-0.5f
		};
        float colors[12] = {
                1,0,0,
                0,1,0,
                0,0,1,
                1,1,1
        };
		VAO* vao=new VAO();
		vao->put(0,2,vertices,8);
        vao->put(1,3,colors,12);
		while (!window->shouldClose())
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
            shader->bind();
            vao->bind();
			glDrawArrays(GL_QUADS, 0, 4);
			vao->unbind();
            shader->unbind();
			/* Swap front and back buffers */
			window->swapBuffer();

			/* Poll for and process events */
			window->pollEvents();
		}

		//delete vao;
		delete shader;
	}
	delete window;
	return 0;

}

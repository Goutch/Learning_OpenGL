#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include "engine/Window.h"
#include "engine/shaders/ShaderProgram.h"

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
		unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);
		
		while (!window->shouldClose())
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
            shader->bind();
			glDrawArrays(GL_QUADS, 0, 4);
            shader->unbind();
			/* Swap front and back buffers */
			window->swapBuffer();

			/* Poll for and process events */
			window->pollEvents();
		}
        shader->unbind();
		delete shader;
	}
	delete window;
	return 0;

}

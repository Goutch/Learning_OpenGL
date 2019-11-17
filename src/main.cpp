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
		std::cout << "OPENGL version:" << glGetString(GL_VERSION) << std::endl;
		/* Loop until the user closes the window */

		//SHADER
		ShaderProgram* shader = new ShaderProgram("src/engine/shaders/shadersSources/BaseVertex.glsl","src/engine/shaders/shadersSources/BaseFragment.glsl");
		shader->bind();
		//VAO

		float vertices[6] = {
			-0.5f,-0.5f,
			0,0.5f,
			0.5f,-0.5f
		};
		unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);
		
		while (!window->shouldClose())
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawArrays(GL_TRIANGLES, 0, 3);
			/* Swap front and back buffers */
			window->swapBuffer();

			/* Poll for and process events */
			window->pollEvents();
		}
		shader->unBind();
		delete shader;
	}
	delete window;
	return 0;

}

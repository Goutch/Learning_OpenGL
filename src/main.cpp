#define GLEW_STATIC

#include <GL/glew.h>
#include <iostream>
#include "engine/Window.h"
#include "engine/shaders/ShaderProgram.h"
#include "engine/graphics/VAO.h"
#include "engine/graphics/DefaultRenderer.h"
#include <array>

int main(void) {
    Window window = Window(900, 600);
    Renderer* renderer =new DefaultRenderer();
    if (window.open()) {
        glewInit() == GLEW_OK ? std::cout << "Initialized GLEW" << std::endl : std::cerr << "FAILED:GLEW INITIALIZATION"
                                                                                         << std::endl;
        std::cout << "OPENGL Version " << glGetString(GL_VERSION) << std::endl;
        /* Loop until the user closes the window */

        //SHADER
        ShaderProgram shader = ShaderProgram("../src/BaseVertex.glsl", "../src/BaseFragment.glsl");

        std::array<VAO *, 10> vaos = std::array<VAO *, 10>();
        for (int i = 0; i < vaos.size(); ++i) {
            float vertices[8] = {
                    ((float) i * (0.5f / vaos.size())), -0.5f,
                    ((float) i * (0.5f / vaos.size())), 0.5f,
                    (((float) i * (0.5f / vaos.size())) + (1.0f / vaos.size())), 0.5f,
                    (((float) i * (0.5f / vaos.size())) + (1.0f / vaos.size())), -0.5f
            };
            float colors[12] = {
                    0, 0, 1,
                    0, 1, 1,
                    1, 1, 0,
                    1, 0, 0
            };
            vaos.at(i) = new VAO();
            vaos.at(i)->put(0, 2, vertices, 8);
            vaos.at(i)->put(1, 3, colors, 12);
        }

        while (!window.shouldClose()) {
            for (auto &vao : vaos) {
                renderer->addToRenderQueue(vao);
            }
            /* Render here */
            shader.bind();
            renderer->render();
            shader.unbind();
            /* Swap front and back buffers */
            window.swapBuffer();

            /* Poll for and process events */
            window.pollEvents();
        }
        for (int i = 0; i < vaos.size(); ++i) {
            delete vaos[i];
        }
    }
    delete renderer;
    return 0;

}

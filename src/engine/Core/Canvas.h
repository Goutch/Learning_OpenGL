#pragma once


#include "Events/WindowResizeListener.h"
#include "Geometry/VAO.h"
#include <list>
#include <Events/CanvasResizeListener.h>
#include <Data/FBO.h>
#include <Shaders/Shader.h>
#include <glm/glm.hpp>

class window;

class Canvas : WindowResizeListener {
private:
    mutable std::list<CanvasResizeListener *> sizeListeners;
    Shader shader = Shader("#version 330 core\n"
                           "layout (location = 0) in vec2 vertexPosition;\n"
                           "layout (location = 1) in vec2 vertexUv;\n"
                           "out vec2 uv;\n"
                           "void main()\n"
                           "{\n"
                           "    gl_Position = vec4(vertexPosition.xy, 0.0, 1.0);\n"
                           "    uv = vertexUv;\n"
                           "}",
                           "#version 330 core\n"
                           "out vec4 FragColor;\n"
                           "in vec2 uv;\n"
                           "uniform sampler2D screenTexture;\n"
                           "void main()\n"
                           "{\n"
                           "    FragColor = texture(screenTexture, uv);\n"
                           "}", true);
    VAO render_space;
    FBO frame_buffer = FBO(FBO::COLOR);
    mat3 pixel_projection;
    const Window *window;
    unsigned int pixel_width;
    unsigned int pixel_height;
    float width = 1;
    float height = 1;
    float offsetX = 0;
    float offsetY = 0;
public:
    Canvas(const Window &window);

    Canvas(const Canvas &parent_viewport, float width, float height, float offsetX = 0, float offsetY = 0);

    ~Canvas();

    unsigned int getPixelWidth() const;

    unsigned int getPixelHeight() const;


    const mat4 getPixelProjection() const;

    const VAO &getRenderSpace() const;

    const FBO &getFrameBuffer() const;

    const Shader &getShader() const;

    void subscribeSizeChange(CanvasResizeListener &l) const;

    void unsubscribeSizeChange(CanvasResizeListener &l) const;

    void onWindowSizeChange(unsigned int width, unsigned int height) override;
};

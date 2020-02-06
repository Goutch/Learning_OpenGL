//
// Created by User on 2020-01-26.
//

#include <Geometry/Geometry.h>
#include "Canvas.h"
#include "Core/Window.h"
#include "Events/CanvasResizeListener.h"
#include <glm/gtx/transform.hpp>
unsigned int Canvas::getPixelHeight() const {
    return pixel_height;
}

unsigned int Canvas::getPixelWidth() const {
    return pixel_width;
}

Canvas::Canvas(const Window &window) {
    this->window = &window;
    this->width = 1;
    this->height = 1;
    this->pixel_width = window.getWidth();
    this->pixel_height = window.getHeight();
    this->window->subscribeSizeChange(*this);
    Geometry::make_quad(render_space,2,2);
    frame_buffer.setSize(pixel_width, pixel_height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height);
}

Canvas::Canvas(const Canvas &parent_viewport, float width, float height, float offsetX, float offsetY) {
    this->window = parent_viewport.window;
    this->width = width;
    this->height = height;
    this->offsetX=offsetX;
    this->offsetY=offsetY;
    pixel_width = static_cast<unsigned int>(window->getWidth() * width);
    pixel_height = static_cast<unsigned int>( window->getHeight() * height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height);
    window->subscribeSizeChange(*this);
    frame_buffer.setSize(pixel_width, pixel_height);
    Geometry::make_quad(render_space,2*width,2*height,offsetX,offsetY);
}


void Canvas::onWindowSizeChange(unsigned int width, unsigned int height) {
    pixel_width = static_cast<unsigned int>(width * this->width);
    pixel_height = static_cast<unsigned int>(height * this->height);
    frame_buffer.setSize(pixel_width, pixel_height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height, -100, 100);
    for (auto l:sizeListeners) {
        l->onViewportSizeChange(pixel_width, pixel_height);
    }
}



Canvas::~Canvas() {
    window->unsubscribeSizeChange(*this);
}

void Canvas::subscribeSizeChange(CanvasResizeListener &l) const {
    sizeListeners.push_back(&l);
}

void Canvas::unsubscribeSizeChange(CanvasResizeListener &l) const {
    sizeListeners.remove(&l);
}

const FBO &Canvas::getFrameBuffer() const {
    return frame_buffer;
}

const VAO &Canvas::getRenderSpace() const {
    return render_space;
}

const Shader &Canvas::getShader() const{
    return shader;
}

const mat4 Canvas::getPixelProjection() const {
    return pixel_projection;
}










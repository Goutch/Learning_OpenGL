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

Canvas::Canvas(const Window &window,const Shader& shader) {
    this->window = &window;
    this->window->subscribeSizeChange(*this);
    subscribed_window = true;

    material.setShader(shader);
    parent_ratio = vec2(1);
    setSize(window.getWidth(),window.getHeight());
}

Canvas::Canvas(const Canvas &parent_canvas,const Shader& shader, unsigned int pixel_width, unsigned int pixel_height, float offsetX,
               float offsetY) {
    this->parent = &parent_canvas;
    parent_canvas.subscribeSizeChange(*this);
    subscribed_parent=true;

    material.setShader(shader);
    transform.translate(vec2(offsetX, offsetY));
    parent_ratio = vec2(pixel_width / parent_canvas.getPixelWidth(), pixel_height - parent_canvas.getPixelHeight());
    setSize(pixel_width,pixel_height);

}


void Canvas::onWindowSizeChange(unsigned int width, unsigned int height) {
    setSize(width,height);
}

void Canvas::onViewportSizeChange(unsigned int width, unsigned int height) {
    pixel_width = static_cast<unsigned int>(width * parent_ratio.x);
    pixel_height = static_cast<unsigned int>(height * parent_ratio.y);
    setSize(pixel_width,pixel_height);

}


Canvas::~Canvas() {
    if (subscribed_window) { window->unsubscribeSizeChange(*this); }
    if (subscribed_parent) {parent->unsubscribeSizeChange(*this);}
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

const mat4 Canvas::getPixelProjection() const {
    return pixel_projection;
}

void Canvas::setSize(unsigned int pixel_width, unsigned int pixel_height) {
    this->pixel_width=pixel_width;
    this->pixel_height=pixel_height;
    transform.scale(vec2(pixel_width,pixel_height));
    for (auto l:sizeListeners) {
        l->onViewportSizeChange(pixel_width, pixel_height);
    }
    frame_buffer.setSize(pixel_width, pixel_height);
    pixel_projection = glm::ortho<float>(0, pixel_width, 0, pixel_height, -100, 100);
}











//
// Created by User on 2020-01-26.
//

#include "Viewport.h"
#include "Core/Window.h"
#include "Events/ViewportResizeListener.h"

unsigned int Viewport::getPixelHeight() const {
    return pixel_height;
}

unsigned int Viewport::getPixelWidth() const {
    return pixel_width;
}

Viewport::Viewport(const Window &window) {
    this->window = &window;
    this->width = 1;
    this->height = 1;
    this->pixel_width = window.getWidth();
    this->pixel_height = window.getHeight();
    this->window->subscribeSizeChange(*this);

    frame_buffer.setSize(pixel_width, pixel_height);
}

Viewport::Viewport(const Viewport &parent_viewport, float width, float height, float offsetX, float offsetY) {
    this->window = parent_viewport.window;
    this->width = width;
    this->height = height;
    pixel_width = static_cast<unsigned int>(window->getWidth() * width);
    pixel_height = static_cast<unsigned int>( window->getHeight() * height);
    window->subscribeSizeChange(*this);
    frame_buffer.setSize(pixel_width, pixel_height);
}

void Viewport::onWindowSizeChange(unsigned int width, unsigned int height) {
    pixel_width = static_cast<unsigned int>(width * this->width);
    pixel_height = static_cast<unsigned int>(height * this->height);
    frame_buffer.setSize(pixel_width, pixel_height);
    for (auto l:sizeListeners) {
        l->onViewportSizeChange(pixel_width, pixel_height);
    }
}

float Viewport::getWidth() const {
    return width;
}

float Viewport::getHeight() const {
    return height;
}

Viewport::~Viewport() {
    window->unsubscribeSizeChange(*this);
}

void Viewport::subscribeSizeChange(ViewportResizeListener &l) const {
    sizeListeners.push_back(&l);
}

void Viewport::unsubscribeSizeChange(ViewportResizeListener &l) const {
    sizeListeners.remove(&l);
}

const FBO &Viewport::getFrameBuffer() const {
    return frame_buffer;
}










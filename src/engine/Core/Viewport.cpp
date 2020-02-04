//
// Created by User on 2020-01-26.
//

#include <Geometry/Geometry.h>
#include "Viewport.h"
#include "Core/Window.h"
#include "Events/ViewportResizeListener.h"
#include <glm/gtx/transform.hpp>
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
    Geometry::make_quad(render_space,2,2);
    frame_buffer.setSize(pixel_width, pixel_height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height, -100, 100);
}

Viewport::Viewport(const Viewport &parent_viewport, float width, float height, float offsetX, float offsetY) {
    this->window = parent_viewport.window;
    this->width = width;
    this->height = height;
    this->offsetX=offsetX;
    this->offsetY=offsetY;
    pixel_width = static_cast<unsigned int>(window->getWidth() * width);
    pixel_height = static_cast<unsigned int>( window->getHeight() * height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height, -100, 100);
    window->subscribeSizeChange(*this);
    frame_buffer.setSize(pixel_width, pixel_height);
    Geometry::make_quad(render_space,2*width,2*height,offsetX,offsetY);
}


void Viewport::onWindowSizeChange(unsigned int width, unsigned int height) {
    pixel_width = static_cast<unsigned int>(width * this->width);
    pixel_height = static_cast<unsigned int>(height * this->height);
    frame_buffer.setSize(pixel_width, pixel_height);
    pixel_projection=glm::ortho<float>(0, pixel_width, 0, pixel_height, -100, 100);
    for (auto l:sizeListeners) {
        l->onViewportSizeChange(pixel_width, pixel_height);
    }
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

const VAO &Viewport::getRenderSpace() const {
    return render_space;
}

const Shader &Viewport::getShader() const{
    return shader;
}

const mat4 Viewport::getPixelProjection() const {
    return pixel_projection;
}










//
// Created by User on 2020-01-26.
//

#include <Geometry/Geometry.h>
#include "Viewport.h"

unsigned int Viewport::getHeight() const {
    return pixel_height;
}

unsigned int Viewport::getWidth() const {
    return pixel_width;
}

Viewport::Viewport(unsigned int width, unsigned int height) {
    Geometry::make_quad(render_space,2,2);
    setSize(width,height);
}

void Viewport::setSize(unsigned int width, unsigned int height) {
    this->pixel_height=height;
    this->pixel_width=width;
}

const VAO &Viewport::getRenderSpace() {
    return render_space;
}

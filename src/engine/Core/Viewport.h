#pragma once


#include "Geometry/VAO.h"
class Viewport {
private:
    unsigned int pixel_width;
    unsigned int pixel_height;
public:
    VAO render_space;
    Viewport(unsigned int width, unsigned int height);
    const VAO& getRenderSpace();
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setSize(unsigned int width, unsigned int height);
};

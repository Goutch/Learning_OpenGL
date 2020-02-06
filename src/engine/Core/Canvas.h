#pragma once


#include "Events/WindowResizeListener.h"
#include <list>
#include <Events/CanvasResizeListener.h>
#include <Data/FBO.h>
#include <Entities/Canvas/CanvasTransform.h>
#include <Shaders/Canvas/CanvasMaterial.h>
class window;

class Canvas : WindowResizeListener,CanvasResizeListener {
private:

    CanvasMaterial material;

    mutable std::list<CanvasResizeListener *> sizeListeners;
    FBO frame_buffer = FBO(FBO::COLOR);
    mat4 pixel_projection;
    const Window *window;
    const Canvas* parent;
    unsigned int pixel_width;
    unsigned int pixel_height;
    bool subscribed_window=false;
    bool subscribed_parent=false;
    glm::vec2 parent_ratio;
    void setSize(unsigned int pixel_width, unsigned int pixel_height);
public:
    CanvasTransform transform;
    Canvas(const Window &window,const Shader& shader);

    Canvas(const Canvas &parent_canvas, const Shader& shader,unsigned int pixel_width, unsigned int pixel_height, float offsetX = 0,
           float offsetY = 0);

    ~Canvas();

    unsigned int getPixelWidth() const;

    unsigned int getPixelHeight() const;

    const mat4 getPixelProjection() const;



    const FBO &getFrameBuffer() const;



    void subscribeSizeChange(CanvasResizeListener &l) const;

    void unsubscribeSizeChange(CanvasResizeListener &l) const;

    void onWindowSizeChange(unsigned int width, unsigned int height) override;
    void onViewportSizeChange(unsigned int width, unsigned int height) override;
};

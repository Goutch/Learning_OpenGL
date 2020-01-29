#pragma once


#include "Events/WindowResizeListener.h"
#include "Geometry/VAO.h"
#include <list>
#include <Events/ViewportResizeListener.h>
#include <Data/FBO.h>
#include <Shaders/Shader.h>

class window;
class Viewport: WindowResizeListener {
private:
    mutable std::list<ViewportResizeListener*> sizeListeners;
    Shader shader= Shader("../src/engine/Shaders/shadersSources/ScreenVertex.glsl",
                                       "../src/engine/Shaders/shadersSources/ScreenFragment.glsl");
    VAO render_space;
    FBO frame_buffer=FBO(FBO::COLOR);
    const Window* window;
    unsigned int pixel_width;
    unsigned int pixel_height;
    float width=1;
    float height=1;
    float offsetX=0;
    float offsetY=0;
public:
    Viewport(const Window& window);
    Viewport(const Viewport& parent_viewport,float width,float height,float offsetX=0,float offsetY=0);
    ~Viewport();
    unsigned int getPixelWidth() const;
    unsigned int getPixelHeight() const;
    float getWidth()const ;
    float getHeight()const ;
    const VAO& getRenderSpace() const;
    const FBO& getFrameBuffer() const;
    const Shader& getShader() const;
    void subscribeSizeChange(ViewportResizeListener& l)const;
    void unsubscribeSizeChange(ViewportResizeListener& l)const ;
    void onWindowSizeChange(unsigned int width, unsigned int height) override;
};

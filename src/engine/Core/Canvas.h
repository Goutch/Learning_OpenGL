#pragma once


#include "Events/WindowResizeListener.h"
#include <list>
#include <Events/CanvasResizeListener.h>
#include <Core/Rendering/FBO.h>
#include <Ressources/Quad.h>
#include <Entities/Transform.h>
#include <Shaders/EntityMaterial.h>
class window;

/**
 * @class Canvas
 * Represent a virtual window of a scene
 */
class Canvas : WindowResizeListener,CanvasResizeListener {
private:
    EntityMaterial material;
    Quad quad=Quad(0.5,0.5);
    mutable std::list<CanvasResizeListener *> sizeListeners;
    FBO frame_buffer = FBO(FBO::COLOR);
    mat4 pixel_projection;
    const Window *window;
    const Canvas* parent;
    int pixel_width;
    int pixel_height;
    bool subscribed_window=false;
    bool subscribed_parent=false;
    glm::vec2 parent_ratio;
public:
    Transform transform;
    Canvas(const Window &window,const Shader& shader);

    Canvas(const Canvas &parent_canvas, const Shader& shader,int pixel_width,int pixel_height, float offsetX = 0,
           float offsetY = 0);
    Canvas(int sizeX=1,int sizeY=1);
    ~Canvas();

    unsigned int getPixelWidth() const;

    unsigned int getPixelHeight() const;

    const mat4 getPixelProjection() const;

    const EntityMaterial& getMaterial() const;

    const FBO &getFrameBuffer() const;

    const VAO& getVAO() const;

    void subscribeSizeChange(CanvasResizeListener &l) const;
    void unsubscribeSizeChange(CanvasResizeListener &l) const;

    void onWindowSizeChange(unsigned int width, unsigned int height) override;
    void onCanvasSizeChange(unsigned int width, unsigned int height) override;

    void setSize(int pixel_width,int pixel_height);
};

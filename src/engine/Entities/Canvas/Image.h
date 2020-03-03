//
// Created by le6mon on 2020-03-03.
//

#ifndef OGL_ENGINE_IMAGE_H
#define OGL_ENGINE_IMAGE_H


#include <Shaders/Canvas/CanvasMaterial.h>
#include "CanvasEntity.h"

class Image : public CanvasEntity{
private:
    CanvasMaterial* canvasMaterial;
public:
    Image(const glm::vec2 &position, float rotation, const  glm::vec2 &scale, CanvasMaterial *canvasMaterial);

    void draw(const Scene &scene) const override;
};


#endif //OGL_ENGINE_IMAGE_H

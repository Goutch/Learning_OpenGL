//
// Created by le6mon on 2020-03-02.
//

#ifndef OGL_ENGINE_ELLIPSE_H
#define OGL_ENGINE_ELLIPSE_H


#include <Ressources/Color.h>
#include "CanvasEntity.h"

class Ellipse : public CanvasEntity {
private:
    Color color;
public:
    Ellipse(glm::vec2 position, glm::vec2 size, Color color);

    void draw(const Scene &scene) const override;
};


#endif //OGL_ENGINE_ELLIPSE_H

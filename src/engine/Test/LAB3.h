//
// Created by Simon on 2020-02-04.
//

#ifndef OGL_ENGINE_LAB3_H
#define OGL_ENGINE_LAB3_H

#include <Core/Scene.h>

class LAB3 : public Scene {
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

    void render() const override;
};



#endif //OGL_ENGINE_LAB3_H

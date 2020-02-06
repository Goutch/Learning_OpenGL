//
// Created by Simon on 2020-02-04.
//

#ifndef OGL_ENGINE_LAB3_H
#define OGL_ENGINE_LAB3_H

#include <Core/Scene.h>
#include "Shaders/FontMaterial.h"
#include <Core/Scene.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>
#include <Shaders/FontMaterial.h>
#include "Entities/Transform.h"

class LAB3 : public Scene {
private:
    Shader shader = Shader("../src/engine/Shaders/shadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/shadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial("../res/font_arial.bmp", 64, 64, shader);
    FontMaterial font2 = FontMaterial("../res/consolas.bmp", 128, 128, shader);
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

    void render() const override;
};



#endif //OGL_ENGINE_LAB3_H

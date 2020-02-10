//
// Created by Simon on 2020-02-10.
//

#ifndef OGL_ENGINE_LAB4_H
#define OGL_ENGINE_LAB4_H


#include <Core/Scene.h>
#include <Shaders/Canvas/CanvasMaterial.h>
#include "Shaders/Shader.h"

class LAB4 : public Scene {
private:
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/LSystemVertex.glsl",
                                   "../src/engine/Shaders/ShadersSources/LSystemFragment.glsl");
    CanvasMaterial material = CanvasMaterial(shader, Color::RED);
    void fractale(float lastX, float lastY, int gen);
public:
    void init(const Canvas &canvas, Renderer &renderer, Window &window) override;

    void draw() const override;
};


#endif //OGL_ENGINE_LAB4_H

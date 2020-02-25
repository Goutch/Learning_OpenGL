#pragma once

#include <Core/Scene.h>

#include <Core/Scene.h>
#include <Shaders/Material.h>
#include <Ressources/Mesh.h>

#include <Shaders/Canvas/FontMaterial.h>
#include <Shaders/Shader.h>


class LAB3 : public Scene {
private:
    Shader shader = Shader("../src/engine/Shaders/shadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/shadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial(shader,"../res/font_arial.bmp", 64, 64);
    FontMaterial font2 = FontMaterial(shader,"../res/consolas.bmp", 128, 128);
public:

    void init(const Canvas &canvas, Renderer &renderer, Window &window) override;

    void draw() const override;
};





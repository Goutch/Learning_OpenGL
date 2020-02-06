//
// Created by Simon on 2020-02-04.
//

#pragma once
#include <Core/Scene.h>
#include "Shaders/Canvas/FontMaterial.h"
#include <Core/Scene.h>
#include <Shaders/Spacial/SpacialMaterial.h>
#include <Geometry/Mesh.h>
#include <Shaders/Canvas/FontMaterial.h>
#include "Entities/Spacial/Transform.h"
#include <Shaders/Shader.h>
class LAB3 : public Scene {
private:
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial(shader,"../res/font_arial.bmp", 64, 64);
public:
    void init(const Canvas &viewport, Renderer &renderer, Window &window) override;

    void render() const override;
};


#pragma once

#include <Core/SpacialScene.h>
#include <Ressources/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/SpacialScene.h"
#include "Geometry/Geometry.h"
#include <Shaders/Shader.h>
class LAB5_Sim : public SpacialScene{
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/LightFragment.glsl");

    LightMaterial bunny_material = LightMaterial(shader, *this);
    Mesh bunny_mesh=Mesh("../res/bunny.obj");

    float v=0;

    Transform pivot;
public:
    void update(float delta) override;

    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;
};


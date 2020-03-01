#pragma once

#include <Core/SpacialScene.h>
#include <Ressources/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/SpacialScene.h"
#include "Geometry/Geometry.h"
#include <Shaders/Shader.h>
class LAB5 : public SpacialScene{
    Shader lightShader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");

    LightMaterial cube_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial bunny_material = LightMaterial(lightShader, *this);


    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh=Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    float v=0;

    DirectionalLight *sun;
    Transform pivot;
public:
    void update(float delta) override;

    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;
};


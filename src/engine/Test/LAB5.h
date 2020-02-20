#pragma once

#include <Core/SpacialScene.h>
#include <Geometry/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Data/Texture.h>
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


    DirectionalLight *sun;

public:
    void init(const Canvas &viewport, Renderer &renderer, Window &window) override;
};


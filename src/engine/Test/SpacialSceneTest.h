#pragma once

#include <Geometry/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Data/Texture.h>
#include "Core/SpacialScene.h"
#include "Geometry/Geometry.h"
#include <Shaders/Shader.h>
class SpacialSceneTest : public SpacialScene {

    Shader shader = Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/DefaultFragment.glsl");
    Shader lightShader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");

    SpacialMaterial cube_material = SpacialMaterial(shader);
    LightMaterial sphere_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial ground_material = LightMaterial(lightShader, ground_texture, *this);
    LightMaterial bunny_material = LightMaterial(lightShader,stone_texture, *this);

    Texture ground_texture = Texture("../res/wall.jpg", false);
    Texture stone_texture= Texture("../res/stone.jpg", false);

    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;

    DirectionalLight *sun;

public:
    void render() const override;

    void update(float delta) override;

public:
    void init(Canvas &viewport, Renderer &renderer, Window &window) override;

};


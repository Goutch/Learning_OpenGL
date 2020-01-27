#pragma once

#include <Geometry/Mesh.h>
#include <Shaders/LightMaterial.h>
#include <Data/Texture.h>
#include "Core/Scene.h"
#include "Geometry/Geometry.h"

class FullSceneTest : public Scene {
    Shader shader = Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                           "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Shader lightShader = Shader("../src/engine/Shaders/shadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/shadersSources/LightFragment.glsl");

    Material cube_material = Material(shader);
    LightMaterial sphere_material = LightMaterial(lightShader);
    LightMaterial dragon_material = LightMaterial(lightShader);
    LightMaterial ground_material = LightMaterial(lightShader, ground_texture);
    LightMaterial bunny_material = LightMaterial(lightShader,stone_texture);

    Texture ground_texture = Texture("../res/wall.jpg");
    Texture stone_texture=Texture("../res/stone.jpg");

    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;

    DirectionalLight *sun;

public:
    void render() const override;

    void update(float delta) override;

public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

};


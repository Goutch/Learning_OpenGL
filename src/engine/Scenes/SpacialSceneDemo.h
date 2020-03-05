#pragma once

#include <Ressources/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/SpacialScene.h"
#include "Geometry/Geometry.h"
#include <Shaders/Shader.h>
class SpacialSceneDemo : public SpacialScene {
    Shader lightShader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");

    Texture wall_texture = Texture("../res/wall.jpg", false);
    Texture stone_texture= Texture("../res/stone.jpg", false);

    LightMaterial sphere_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial ground_material = LightMaterial(lightShader, Color(0.2,0.7,0.1), *this);
    LightMaterial bunny_material = LightMaterial(lightShader,wall_texture, *this);



    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;

    DirectionalLight *sun;

public:
    void update(float delta) override;

public:
    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;

};


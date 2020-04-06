#pragma once

#include <Ressources/Mesh.h>
#include <Ressources/Shaders/Material/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/Scene.h"
#include "Utils/Geometry.h"
#include <Ressources/Shaders/Shader.h>
#include <Entities/Camera.h>
#include "Core/Canvas.h"
class Grass;
class SpacialSceneDemo : public Scene {
    Shader lightShader = Shader("../res/shaders/LightVertex.glsl",
                                "../res/shaders/LightFragment.glsl");
    Shader default_shader= Shader("../res/shaders/DefaultVertex.glsl",
                                "../res/shaders/DefaultFragment.glsl");
    Shader edge_shader=Shader("../res/shaders/EdgeDetectionVertex.glsl",
                                "../res/shaders/EdgeDetectionFragment.glsl");\

    Texture wall_texture = Texture("../res/wall.jpg", false);

    LightMaterial sphere_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial ground_material = LightMaterial(lightShader, Color(.5,.7,.4,1), *this);
    LightMaterial bunny_material = LightMaterial(lightShader,wall_texture, *this);
    EntityMaterial player_material=EntityMaterial(default_shader, Color::BLUE);

    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;
    DirectionalLight *sun;

public:
    ~SpacialSceneDemo();
    void render() const override;

    void draw() const override;

    void update(float delta) override;

    void init(Canvas &canvas, Renderer &renderer, Input &input) override;

};


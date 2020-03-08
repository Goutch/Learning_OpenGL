#pragma once

#include <Ressources/Mesh.h>
#include <Shaders/Spacial/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/SpacialScene.h"
#include "Geometry/Geometry.h"
#include <Shaders/Shader.h>
#include "Core/Canvas.h"
class Grass;
class SpacialSceneDemo : public SpacialScene {
    Shader lightShader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");
    Shader default_shader= Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/DefaultFragment.glsl");
    Shader mirror_shader=Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/MirrorFragment.glsl");\

    Texture wall_texture = Texture("../res/wall.jpg", false);

    LightMaterial sphere_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial ground_material = LightMaterial(lightShader, Color(0.6,0.85,0.1), *this);
    LightMaterial bunny_material = LightMaterial(lightShader,wall_texture, *this);
    SpacialMaterial player_material=SpacialMaterial(default_shader,Color::BLUE);
    SpacialMaterial mirror_material=SpacialMaterial(mirror_shader);

    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;
    Quad mirror_quad;

    Canvas mirror_canvas=Canvas(600,600);
    Transform mirror_camera;
    mat4 projection_mirror;

    DirectionalLight *sun;

    Grass* grass;
public:
    ~SpacialSceneDemo();
    void render() const override;

    void draw() const override;

public:
    void update(float delta) override;

public:
    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;

};


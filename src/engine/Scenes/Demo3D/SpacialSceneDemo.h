#pragma once

#include <Ressources/Mesh.h>
#include <Shaders/LightMaterial.h>
#include <Ressources/Texture.h>
#include "Core/Scene.h"
#include "Utils/Geometry.h"
#include <Shaders/Shader.h>
#include <Entities/Camera.h>
#include "Core/Canvas.h"
class Grass;
class SpacialSceneDemo : public Scene {
    Shader lightShader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");
    Shader default_shader= Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/DefaultFragment.glsl");
    Shader mirror_shader=Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/MirrorFragment.glsl");\

    Texture wall_texture = Texture("../res/wall.jpg", false);

    LightMaterial sphere_material = LightMaterial(lightShader, *this);
    LightMaterial dragon_material = LightMaterial(lightShader, *this);
    LightMaterial ground_material = LightMaterial(lightShader, Color(.5,.7,.4,1), *this);
    LightMaterial bunny_material = LightMaterial(lightShader,wall_texture, *this);
    EntityMaterial player_material=EntityMaterial(default_shader, Color::BLUE);
    EntityMaterial mirror_material=EntityMaterial(mirror_shader);

    Mesh dragon_mesh = Mesh("../res/dragon.obj");
    Mesh bunny_mesh = Mesh("../res/bunny.obj");
    Mesh cube_mesh;
    Mesh sphere_mesh;
    Quad mirror_quad;

    Canvas mirror_canvas=Canvas(600,600);
    Camera *mirror_camera;


    DirectionalLight *sun;

    Grass* grass;
public:
    ~SpacialSceneDemo();
    void render() const override;

    void draw() const override;

    void update(float delta) override;

    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;

};


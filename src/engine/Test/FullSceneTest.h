#pragma once

#include <Geometry/Mesh.h>
#include <Shaders/Material.h>
#include <Data/Texture.h>
#include "Core/Scene.h"
#include "Geometry/Geometry.h"
class FullSceneTest :public Scene{
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                         "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");

    Material dragon_material=Material(shader,Color::RED);
    Texture ground_texture=Texture("../res/wall.jpg");
    Material ground_material=Material(shader,ground_texture);
    Mesh dragon=Mesh("../res/dragon.obj");
    Mesh plane;
    Mesh cube;
   // Mesh dragon_model=Mesh("../res/dragon.obj");

public:
    void init(Window &window, Renderer &renderer) override;

};


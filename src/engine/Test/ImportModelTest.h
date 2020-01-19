#pragma once


#include <Shaders/Shader.h>
#include <Shaders/Material.h>
#include "Shaders/LightMaterial.h"
#include <Data/Texture.h>
#include <Geometry/Mesh.h>
#include "Core/Scene.h"
class ImportModelTest: public Scene {
private:
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                         "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");

    Material material=Material(shader);


    Mesh mesh=Mesh("../res/dragon.obj");
public:
    void init(Window &window, Renderer &renderer) override;

};

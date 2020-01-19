#pragma once


#include <Shaders/Shader.h>
#include <Shaders/Material.h>
#include <Data/Texture.h>
#include <Geometry/Mesh.h>
#include "Core/Scene.h"
class ImportModelTest: public Scene {
private:
    Shader shader=Shader("../src/engine/Shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Shaders/shadersSources/EntityFragment.glsl");
    Material material=Material(shader);
    Mesh mesh=Mesh("../res/dragon.obj");
public:
    void init(Window &window, Renderer &renderer) override;

};

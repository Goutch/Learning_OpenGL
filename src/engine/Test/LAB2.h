#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>

class LAB2 : public Scene{
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                                           "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Texture textures[2]={Texture("../res/stone.jpg"),Texture("../res/wall.jpg")};
    Material materials[2]={Material(shader,textures[0]),Material(shader,textures[1])};
    Mesh quad;
public:
    void init(Window &window, Renderer &renderer) override;

};
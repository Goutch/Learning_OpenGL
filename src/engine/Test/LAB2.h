#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>

class LAB2 : public Scene{
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                                           "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Texture textures[3]={Texture("../res/s-l300.jpg"),Texture("../res/Thank_U,_Next_album_cover.png"),Texture("../res/SabbathBorn.jpg")};
    Material materials[3]={Material(shader,textures[0]),Material(shader,textures[1]),Material(shader,textures[2])};
    Mesh quad;
public:
    void init(Window &window, Renderer &renderer) override;

};
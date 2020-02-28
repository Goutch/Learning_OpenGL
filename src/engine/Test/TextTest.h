#pragma  once

#include <Core/Scene.h>
#include <Ressources/Texture.h>
#include <Ressources/AtlasTexture.h>
#include <Shaders/Spacial/SpacialMaterial.h>
#include <Ressources/Mesh.h>
#include <Shaders/Canvas/FontMaterial.h>
#include "Entities/Spacial/Transform.h"
#include <Events/KeyPressListener.h>
#include <Shaders/Shader.h>
class TextTest : public Scene{
    Transform transform = Transform();
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial(shader,"../res/consolas.bmp",128, 128);

public:
    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;

};



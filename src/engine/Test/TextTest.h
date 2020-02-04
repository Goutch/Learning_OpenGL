#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Data/AtlasTexture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>
#include <Shaders/FontMaterial.h>
#include "Entities/Transform.h"
#include <Events/KeyPressListener.h>
class TextTest : public Scene{
    Transform transform = Transform();
    Shader shader = Shader("../src/engine/Shaders/shadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/shadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial("../res/font.bmp", 64, 64, shader);
    Mesh vao;

public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

    void render() const override;

};



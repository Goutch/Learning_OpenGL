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
#include <Core/SpacialScene.h>

class BaseScene : public SpacialScene{
public:
    void init(const Canvas &viewport, Renderer &renderer, Input &input) override;

    void draw() const override;
};



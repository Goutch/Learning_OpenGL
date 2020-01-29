#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>

class LAB2 : public Scene{

public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;
};
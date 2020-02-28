#pragma once

#include <Core/Scene.h>

#include <Core/Scene.h>
#include <Shaders/Material.h>
#include <Ressources/Mesh.h>

#include <Shaders/Canvas/FontMaterial.h>
#include <Shaders/Shader.h>


class ApplicationDrawing2D : public Scene {
private:
    mutable Color color;
public:

    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    void draw() const override;
};





#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>

class LAB2 : public Scene{
    Shader shader = Shader("../src/engine/Shaders/shadersSources/PrimitiveVertex.glsl",
                           "../src/engine/Shaders/shadersSources/PrimitiveFragment.glsl");
    Texture texture = Texture("../res/wall.jpg");
    Material material = Material(shader, texture);
    VAO vao;
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

    void render() const override;
};
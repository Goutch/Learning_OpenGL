#pragma once
#include <glm/vec3.hpp>
#include "Entity.h"
class Mesh;
class MeshRenderer :public Entity{
    BaseShader* shader;
    Mesh* mesh;
public:
    MeshRenderer(Mesh* mesh,BaseShader* shader,glm::vec3 pos);

    BaseShader &getShader() override;

    Drawable &getDrawable() override;

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;
};



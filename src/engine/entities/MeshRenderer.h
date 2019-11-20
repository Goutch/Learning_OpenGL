#pragma once
#include <glm/vec3.hpp>
#include "Entity.h"

class MeshRenderer :public Entity{
    ShaderProgram* shader;
    Mesh* mesh;
public:
    MeshRenderer(Mesh& mesh,ShaderProgram& shader,glm::vec3 pos);

    ShaderProgram &getShader() override;

    Transform &getTranform() override;

    Mesh &getMesh() override;

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;
};



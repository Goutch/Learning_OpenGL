#pragma once
#include <glm/vec3.hpp>
#include "Transform.h"
#include "Entity.h"
#include "graphics/shaders/ShaderProgram.h"
class MeshRenderer :public Entity{
    Transform transform;
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


ShaderProgram &MeshRenderer::getShader() {
    return *shader;
}

Transform &MeshRenderer::getTranform() {
    return transform;
}

Mesh &MeshRenderer::getMesh() {
    return *mesh;
}

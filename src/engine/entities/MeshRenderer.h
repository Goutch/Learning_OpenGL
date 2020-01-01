#pragma once
#include <glm/vec3.hpp>
#include "Entity.h"
class Mesh;
class MeshRenderer :public Entity{
    EntityShader* shader;
    VAO* mesh;
public:
    MeshRenderer(VAO* mesh, EntityShader* shader, glm::vec3 pos);

    EntityShader &getShader() override;

    VAO &getVAO() override;

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;
};



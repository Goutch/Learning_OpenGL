#pragma once
#include "Renderer.h"
#include <queue>
#include <tuple>
#include <Shaders/Shader.h>

class SimpleRenderer:public Renderer {
    mutable std::queue<std::tuple<const Material*,const VAO*,const Transform*>> render_queue;

public:

    void draw(const VAO &vao, const Material &material , const Transform& transform) override;

    void render(const FBO &buffer,const glm::mat4 &projection=mat4(1.0f),const glm::mat4& view_mat=mat4(1.0f)) override;

    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) override;

    void renderUI(const FBO &buffer, const mat4 &projection) override;

    void drawUI(const VAO &vao, const Material &material, const Transform &transform) override;

};



#pragma once
#include "Renderer.h"
#include <queue>
#include <tuple>
#include <Shaders/Shader.h>

class SimpleRenderer:public Renderer {
    mutable std::queue<std::tuple<const SpacialMaterial*,const VAO*,const Transform*>> render_queue;

public:

    void draw(const VAO &vao, const SpacialMaterial &material , const Transform& transform)const  override;

    void renderSpace(const FBO &buffer, const glm::mat4 &projection=mat4(1.0f), const glm::mat4& view_mat=mat4(1.0f))const  override;

    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat)const  override;


};



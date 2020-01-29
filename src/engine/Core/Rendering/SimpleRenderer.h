#pragma once
#include "Renderer.h"
#include <queue>
#include <tuple>
#include <Shaders/Shader.h>

class SimpleRenderer:public Renderer {
    mutable std::queue<std::tuple<const Material*,const VAO*,const Transform*>> render_queue;
    Shader depthShader = Shader("../src/engine/Shaders/shadersSources/DepthVertex.glsl",
                                "../src/engine/Shaders/shadersSources/DepthFragment.glsl");
    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;
public:
    SimpleRenderer();
    void addToRenderQueue(const VAO &vao, const Material &material ,const Transform& transform) override;

    void render(const FBO &buffer, const Scene &scene, const mat4 &space_mat) override;

    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) override;



};



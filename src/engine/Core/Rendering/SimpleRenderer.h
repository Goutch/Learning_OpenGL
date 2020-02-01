#pragma once
#include "Renderer.h"
#include <queue>
#include <tuple>
#include <Shaders/Shader.h>

class SimpleRenderer:public Renderer {
    mutable std::queue<std::tuple<const Material*,const VAO*,const Transform*>> render_queue;
    Shader depthShader = Shader("#version 330 core\n"
                                "layout(location = 0) in vec3 vertexPosition;\n"
                                "uniform mat4 space;\n"
                                "uniform mat4 transform;\n"
                                "void main(){\n"
                                "    gl_Position =  space *transform* vec4(vertexPosition,1);\n"
                                "}",
                                "#version 330 core\n"
                                "out float fragmentdepth;\n"
                                "void main(){\n"
                                "    fragmentdepth =gl_FragCoord.z;\n"
                                "}",true);
    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;
public:
    SimpleRenderer();
    void draw(const VAO &vao, const Material &material , const Transform& transform) override;

    void render(const FBO &buffer,const glm::mat4 &projection=mat4(1.0f),const glm::mat4& view_mat=mat4(1.0f)) override;

    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) override;



};



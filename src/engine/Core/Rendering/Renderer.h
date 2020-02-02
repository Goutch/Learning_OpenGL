#pragma once

#include "glm/mat4x4.hpp"
#include <Shaders/Material.h>
class MeshRenderer;

class Window;

class Transform;

class VAO;

class Scene;

class Shader;

class Camera;

class Texture;

class FBO;

using namespace glm;

class Viewport;

#include <Data/Color.h>
#include <Entities/Transform.h>
#include <Geometry/Quad.h>
#include <queue>
#include <tuple>

class Renderer {
protected:
    struct Primitive{
        enum PrimitiveType{
            Ellipse,
            Rect,
        };
        Color color;
        Transform transform;
        PrimitiveType type;
        Primitive(Transform transform,Color color,PrimitiveType type){
            this->transform=transform;
            this->color=color;
            this->type=type;
        };
    };
    std::queue<Primitive> primitive_queue;
    const Quad QUAD;



    const Shader DEFAULT_SHADER=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                                                  "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    const Shader DEPTH_SHADER = Shader("#version 330 core\n"
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
                                       "}", true);
    const Shader ELLIPSE_SHADER=Shader("#version 330 core\n"
                                       "uniform mat4 projection;\n"
                                       "uniform mat4 transform;\n"
                                       "layout(location=0)in vec3 vertexPosition;\n"
                                       "layout(location=1)in vec2 vertexUv;\n"
                                       "out vec2 uv;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    uv=vertexUv;\n"
                                       "    gl_Position=projection*transform*vec4(vertexPosition.xyz,1.);\n"
                                       "}",
                                       "#version 330 core\n"
                                       "uniform vec4 material_color;\n"
                                       "in vec2 uv;\n"
                                       "out vec4 fragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    vec2 coord=uv-.5;\n"
                                       "    if (distance(coord, vec2(0, 0))>0.5)\n"
                                       "    { fragColor=vec4(0, 0, 0, 0); }\n"
                                       "    else\n"
                                       "    { fragColor=material_color; }\n"
                                       "}",true);;
    const Shader PRIMITIVE_SHADER=Shader("#version 330 core\n"
                                       "uniform mat4 projection;\n"
                                       "uniform mat4 transform;\n"
                                       "layout(location=0)in vec3 vertexPosition;\n"
                                       "layout(location=1)in vec2 vertexUv;\n"
                                       "out vec2 uv;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    uv=vertexUv;\n"
                                       "    gl_Position=projection*transform*vec4(vertexPosition.xyz,1.);\n"
                                       "}",
                                       "#version 330 core\n"
                                       "uniform vec4 material_color;\n"
                                       "in vec2 uv;\n"
                                       "out vec4 fragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    fragColor=material_color;\n"
                                       "}",true);;

     Material PRIMITIVE_MATERIAL=Material(PRIMITIVE_SHADER);
     Material ELLIPSE_MATERIAL=Material(ELLIPSE_SHADER);
    const Material DEFAULT_MATERIAL=Material(DEFAULT_SHADER);
    const Transform DEFAULT_TRANSFORM=Transform();

    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;

public:

    Renderer();
    void clear();
    void clearDepth();
    void clearColor();

    virtual void draw(const VAO &vao, const Shader &shader, const Texture &texture);

    virtual void render(const FBO &buffer, const glm::mat4 &projection = mat4(1.0f), const glm::mat4 &view_mat = mat4(1.0f)) = 0;
    virtual void draw(const VAO &vao, const Material &material, const Transform &transform)=0;
    virtual void draw(const VAO &vao);
    virtual void draw(const VAO &vao, const Material &material);
    virtual void draw(const VAO &vao,const Transform& transform);

    virtual void renderUI(const FBO &buffer, const glm::mat4 &projection = mat4(1.0f))=0;
    virtual void drawUI(const VAO &vao, const Material &material, const Transform &transform)=0;
    virtual void drawUI(const VAO &vao);
    virtual void drawUI(const VAO &vao, const Material &material);
    virtual void drawUI(const VAO &vao,const Transform& transform);

    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) = 0;

    virtual void renderPrimitives(const FBO &buffer, const glm::mat4 &projection);
    virtual void drawRect(float x, float y, float width, float height, const Color& color);
    virtual void drawEllipse(float x, float y, float width, float height, const Color& color);
    virtual void drawLine(float x1, float y1, float x2, float y2, float width, const Color& color);

    void wireframe(bool enable);
};

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
        Color color;
        Transform transform;
        Shader* shader;
        Primitive(Transform transform,Color color,Shader& shader){
            this->transform=transform;
            this->color=color;
            this->shader=&shader;
        };
    };
    std::queue<Primitive> primitives_queue;

    const Quad QUAD;

    const Shader DEFAULT_SHADER=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                                                  "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");;
    const Shader ELLIPSE_SHADER=Shader("../src/engine/Shaders/shadersSources/EllipseVertex.glsl",
                                       "../src/engine/Shaders/shadersSources/EllipseFragment.glsl");;
    const Material DEFAULT_MATERIAL=Material(DEFAULT_SHADER);
     Material primitive_material=Material(DEFAULT_SHADER);
    const Transform DEFAULT_TRANSFORM=Transform();

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
    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;

public:

    Renderer();
    void clear();
    void clearDepth();
    void clearColor();

    virtual void render(const FBO &buffer, const glm::mat4 &projection = mat4(1.0f), const glm::mat4 &view_mat = mat4(1.0f)) = 0;
    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) = 0;
    virtual void draw(const VAO &vao, const Material &material, const Transform &transform)=0;
    virtual void draw(const VAO &vao);
    virtual void draw(const VAO &vao, const Material &material);
    virtual void draw(const VAO &vao,const Transform& transform);
    virtual void draw(const VAO &vao, const Shader &shader, const Texture &texture);
    virtual void drawRect(float x,float y,float width, float height,const Color& color);
    virtual void drawEllipse(float x, float y, float width, float height,const Color& color);
    virtual void drawLine(float x1,float y1,float x2,float y2,float width,const Color& color);

    void wireframe(bool enable);
};

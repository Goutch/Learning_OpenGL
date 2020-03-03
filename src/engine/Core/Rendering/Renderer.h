#pragma once

#include "glm/mat4x4.hpp"
#include <Shaders/Spacial/SpacialMaterial.h>

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

class Canvas;

class CanvasMaterial;

#include <Ressources/Color.h>
#include <Entities/Spacial/Transform.h>
#include <Ressources/Quad.h>
#include <queue>
#include <tuple>
#include <Entities/Canvas/CanvasTransform.h>
#include <Shaders/Shader.h>
#include <Shaders/Canvas/CanvasMaterial.h>
#include <deque>
class Renderer {
protected:
    struct CanvasElement {
        const CanvasTransform *transform;
        const CanvasMaterial *material;
        const VAO *vao;

        CanvasElement(const CanvasTransform &transform, const CanvasMaterial &material, const VAO &vao) {
            this->transform = &transform;
            this->material = &material;
            this->vao = &vao;
        }
    };

    mutable std::queue<CanvasElement> canvas_elements;

public:
    const Quad QUAD=Quad();
    const Shader DEFAULT_SPACIAL_SHADER = Shader("../src/engine/Shaders/ShadersSources/DefaultVertex.glsl",
                                                 "../src/engine/Shaders/ShadersSources/DefaultFragment.glsl");
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
    const Shader ELLIPSE_SHADER = Shader("#version 330 core\n"
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
                                         "    if (distance(uv, vec2(0.5, 0.5))>0.5)\n"
                                         "    { fragColor=vec4(0, 0, 0, 0); }\n"
                                         "    else\n"
                                         "    { fragColor=material_color; }\n"
                                         "}", true);;
    const Shader DEFAULT_CANVAS_SHADER = Shader("#version 330 core\n"
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
                                                "uniform sampler2D texture_0;\n"
                                                "uniform int has_texture;\n"
                                                "uniform vec4 material_color;\n"
                                                "in vec2 uv;\n"
                                                "out vec4 fragColor;\n"
                                                "void main()\n"
                                                "{\n"
                                                "    if(has_texture==1)\n"
                                                "    {\n"
                                                "        vec4 texColor0=texture(texture_0,uv);\n"
                                                "        fragColor=texColor0*material_color;\n"
                                                "    }\n"
                                                "    else{\n"
                                                "        fragColor=material_color;\n"
                                                "    }\n"
                                                "}", true);;

protected:

    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;
    mutable std::deque<CanvasMaterial> temp_materials;
    mutable std::deque<CanvasTransform> temp_transforms;
    mutable std::deque<VAO> temp_vaos;
public:
    const CanvasMaterial DEFAULT_CANVAS_MATERIAL = CanvasMaterial(DEFAULT_CANVAS_SHADER);
    const SpacialMaterial DEFAULT_SPACIAL_MATERIAL = SpacialMaterial(DEFAULT_SPACIAL_SHADER);
    const SpacialMaterial ELLIPSE_MATERIAL = SpacialMaterial(ELLIPSE_SHADER);
    const Transform DEFAULT_TRANSFORM = Transform();


    Renderer();

    void clear() const ;

    void clearDepth() const ;

    void clearColor() const ;

    virtual void renderOnMainBuffer(const Canvas &canvas);

    virtual void draw(const VAO &vao, const SpacialMaterial &material, const Transform &transform) const= 0;

    virtual void renderSpace(const FBO &buffer, const glm::mat4 &projection, const glm::mat4 &view_mat) const= 0;

    virtual void draw(const VAO &vao, const CanvasTransform &transform, const CanvasMaterial &material) const;

    virtual void renderCanvas(const FBO &buffer, const glm::mat4 &projection) const;

    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const = 0;
    void drawRect(float x, float y, float width, float height, const Color &color);
    void drawLine(float x1, float y1, float x2, float y2, float width, const Color &color);
    void drawEllipse(float x, float y, float width, float height, const Color &color);
    void drawTriangle(float x1, float y1,float x2,float y2,float x3,float y3, const Color &color);
    void wireframe(bool enable);

};

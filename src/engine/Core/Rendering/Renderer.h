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

#include <Data/Color.h>
#include <Entities/Spacial/Transform.h>
#include <Geometry/Quad.h>
#include <queue>
#include <tuple>
#include <Entities/Canvas/CanvasTransform.h>
#include <Shaders/Shader.h>
#include <Shaders/Canvas/CanvasMaterial.h>

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
    const Quad QUAD;

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
                                                "uniform vec4 material_color;\n"
                                                "in vec2 uv;\n"
                                                "out vec4 fragColor;\n"
                                                "void main()\n"
                                                "{\n"
                                                "    fragColor=material_color;\n"
                                                "}", true);;

protected:

    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;
public:
    const CanvasMaterial DEFAULT_CANVAS_MATERIAL = CanvasMaterial(DEFAULT_CANVAS_SHADER);
    const SpacialMaterial DEFAULT_SPACIAL_MATERIAL = SpacialMaterial(DEFAULT_SPACIAL_SHADER);
    const SpacialMaterial ELLIPSE_MATERIAL = SpacialMaterial(ELLIPSE_SHADER);
    const Transform DEFAULT_TRANSFORM = Transform();

    Renderer();

    void clear() const ;

    void clearDepth() const ;

    void clearColor() const ;

    virtual void drawCanvas(const Canvas &canvas);

    virtual void drawCanvas(const FBO &buffer, const Canvas &canvas);


    virtual void draw(const VAO &vao, const SpacialMaterial &material, const Transform &transform) const= 0;

    virtual void renderSpace(const FBO &buffer, const glm::mat4 &projection, const glm::mat4 &view_mat) const= 0;

    virtual void draw(const VAO &vao, const CanvasTransform &transform, const CanvasMaterial &material) const;

    virtual void renderCanvas(const FBO &buffer, const glm::mat4 &projection) const;

    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const = 0;

    void wireframe(bool enable);
};

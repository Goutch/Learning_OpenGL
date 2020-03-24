#pragma once



class MeshRenderer;

class Window;

class Transform;

class VAO;

class Scene;

class Shader;

class Camera;

class Texture;

class FBO;

class Canvas;

#include "glm/mat4x4.hpp"
#include <Ressources/Shaders/Material/EntityMaterial.h>
#include <Ressources/Color.h>
#include <Entities/Transform.h>
#include <Ressources/Quad.h>
#include <queue>
#include <tuple>
#include <Ressources/Shaders/Shader.h>
#include <Ressources/Sphere.h>
#include <Ressources/Cube.h>
#include <deque>
using namespace glm;


class Renderer {
protected:
    mutable unsigned int draw_count=0;
    mutable unsigned int vertices_count=0;
public:
    static const int PRIMITIVE_TRIANGLES;
    static const int PRIMITIVE_POINTS;

    struct RenderOption{
        bool cull_faces=true;
        int primitive_type=PRIMITIVE_TRIANGLES;
        bool depth_test=true;
        RenderOption(){}
        RenderOption(const RenderOption& other){
            this->cull_faces=other.cull_faces;
            this->depth_test=other.depth_test;
            this->primitive_type=other.primitive_type;
        }
        bool operator==(const RenderOption& other)const{
            return (primitive_type==other.primitive_type&&
                    cull_faces==other.cull_faces&&
                    depth_test==other.depth_test);
        }

    };


    const Quad QUAD=Quad();
    const Cube CUBE = Cube();
    const Sphere SPHERE = Sphere(1, 100, 50);
    const Shader DEFAULT_SPACIAL_SHADER = Shader("../res/shaders/DefaultVertex.glsl",
                                                 "../res/shaders/DefaultFragment.glsl");
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
    const Shader DEFAULT_2D_SHADER = Shader("#version 330 core\n"
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
public:
    const EntityMaterial DEFAULT_2D_MATERIAL = EntityMaterial(DEFAULT_2D_SHADER);
    const EntityMaterial DEFAULT_3D_MATERIAL = EntityMaterial(DEFAULT_SPACIAL_SHADER);

    Renderer();

    void clear() const ;

    void clearDepth() const ;

    void clearColor() const ;

    virtual void renderOnMainBuffer(const Canvas &canvas);

    virtual void draw(const VAO &vao, const EntityMaterial &material, const Transform &transform,RenderOption renderOption={}) const= 0;

    virtual void render(const FBO &buffer, const glm::mat4 &projection, const glm::mat4 &view_mat=mat4(1.0f)) const= 0;


    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const = 0;
    void wireframe(bool enable);
    void screenShot(int width,int height);
    unsigned int getVerticesCount();
    unsigned int getDrawCount();
};

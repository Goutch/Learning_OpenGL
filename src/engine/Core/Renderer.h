#pragma once


#include "glm/mat4x4.hpp"
#include "Data/Texture.h"
#include "Geometry/VAO.h"
#include "Events/WindowResizeListener.h"
#include <unordered_map>
#include "list"
#include "Geometry/Geometry.h"
#include "Shaders/Shader.h"
#include "Data/FBO.h"
#include "Data/RBO.h"

class MeshRenderer;

class Window;

class Transform;

class Material;

class VAO;

class Scene;

class Shader;

class Camera;

using namespace glm;

class Viewport;

class Renderer {
private:

    Shader depthShader = Shader("../src/engine/Shaders/shadersSources/DepthVertex.glsl",
                                "../src/engine/Shaders/shadersSources/DepthFragment.glsl");
    int depthShader_light_space_matrix_location;
    int depthShader_transform_mat_location;
    mutable std::unordered_map<const Material *, std::unordered_map<const VAO *, std::list<const Transform *>>> material_batch;

public:

    Renderer();

    ~Renderer();

    virtual void addToRenderQueue(const Material &material, const VAO &vao, const Transform &transform);

    void clear();
    void clearDepth();
    void clearColor();

    virtual void draw(const Texture& texture,const VAO& quad,const Shader& shader);

    virtual void render(const FBO &buffer, const Scene &scene, const glm::mat4 &space_mat);

    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat);


};
#pragma once


#include "glm/mat4x4.hpp"
#include <unordered_map>
#include "list"
#include "Renderer.h"
#include "Shaders/Shader.h"
class MeshRenderer;

class Material;

class VAO;

class Scene;

class Shader;

class Camera;

using namespace glm;

class BatchRenderer:public Renderer {
private:

    mutable std::unordered_map<const Material *, std::unordered_map<const VAO *, std::list<const Transform*>>> material_batch;

public:


    void draw(const VAO &vao, const Material &material, const Transform& transform) override ;
    void render(const FBO &buffer,const glm::mat4 &projection=mat4(1.0f),const glm::mat4& view_mat=mat4(1.0f)) override ;
    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) override ;

};
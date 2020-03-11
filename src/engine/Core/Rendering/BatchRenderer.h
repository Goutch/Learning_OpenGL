#pragma once

#include "Renderer.h"
#include "glm/mat4x4.hpp"
#include <unordered_map>
#include "list"

#include "Shaders/Shader.h"
class MeshRenderer;

class EntityMaterial;

class VAO;

class Scene;

class Shader;

class Camera;

using namespace glm;

class BatchRenderer:public Renderer {
private:

    mutable std::unordered_map<RenderOption,std::unordered_map<const EntityMaterial *, std::unordered_map<const VAO *, std::list<std::tuple<const Transform*,int,bool>>>>> batches;

public:


    void draw(const VAO &vao, const EntityMaterial &material, const Transform& transform,RenderOption options) const override ;
    void render(const FBO &buffer, const glm::mat4 &projection= mat4(1.0f), const glm::mat4& view_mat= mat4(1.0f)) const override ;
    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const override ;

};
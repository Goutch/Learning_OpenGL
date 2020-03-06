#pragma once

#include "Renderer.h"
#include "glm/mat4x4.hpp"
#include <unordered_map>
#include "list"

#include "Shaders/Shader.h"
class MeshRenderer;

class SpacialMaterial;

class VAO;

class Scene;

class Shader;

class Camera;

using namespace glm;

class BatchRenderer:public Renderer {
private:

    mutable std::unordered_map<const SpacialMaterial *, std::unordered_map<const VAO *, std::list<std::tuple<const Transform*,int,bool>>>> spacial_material_batch;

public:


    void draw(const VAO &vao, const SpacialMaterial &material, const Transform& transform,int primitive,bool cull_faces) const override ;
    void renderSpace(const FBO &buffer, const glm::mat4 &projection= mat4(1.0f), const glm::mat4& view_mat= mat4(1.0f)) const override ;
    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const override ;

};
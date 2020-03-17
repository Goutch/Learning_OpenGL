#pragma once

#include "Renderer.h"
#include "glm/mat4x4.hpp"
#include <unordered_map>
#include "list"

#include "Ressources/Shaders/Shader.h"

class MeshRenderer;

class EntityMaterial;

class VAO;

class Scene;

class Shader;

class Camera;

using namespace glm;


class BatchRenderer : public Renderer {
private:
    struct Hash_fun {
        std::size_t operator()(const RenderOption &o) const {
            return (o.primitive_type * 4)
                   + (o.cull_faces ? 2 : 0)
                   + (o.depth_test ? 1 : 0);
        }
    };

    mutable std::array<std::unordered_map<
            RenderOption, std::unordered_map<
                    const EntityMaterial *, std::unordered_map<
                            const VAO *, std::list<const Transform *>
                    >
            >, Hash_fun
    >,2> batches;

public:
    void draw(const VAO &vao, const EntityMaterial &material, const Transform &transform,
              RenderOption options) const override;

    void render(const FBO &buffer, const glm::mat4 &projection = mat4(1.0f),
                const glm::mat4 &view_mat = mat4(1.0f)) const override;

    void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const override;

};
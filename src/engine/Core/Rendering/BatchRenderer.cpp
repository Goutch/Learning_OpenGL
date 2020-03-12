#define GLEW_STATIC

#include <GL/glew.h>
#include "BatchRenderer.h"
#include "Ressources/VAO.h"
#include "Ressources/Shaders/Material/EntityMaterial.h"
#include "Entities/Transform.h"
#include "Core/Log.h"
#include "Core/Scene.h"

#include "Core/Rendering/FBO.h"

void BatchRenderer::render(const FBO &buffer, const mat4 &projection, const mat4 &view_mat) const {
    Log::message("render");
    buffer.bind();
    clear();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    for (auto option_batch:batches) {
        const RenderOption& option=option_batch.first;
        option.cull_faces?glEnable(GL_CULL_FACE):glDisable(GL_CULL_FACE);
        option.depth_test?glEnable(GL_DEPTH_TEST):glDisable(GL_CULL_FACE);
        for (auto &material_batch:option_batch.second) {
            const EntityMaterial &material = *material_batch.first;
            material.bind();
            material.projection(projection);
            material.view(view_mat);
            for (auto &vao_batch:material_batch.second) {
                const VAO &vao = *vao_batch.first;
                vao.bind();
                for (auto &transform:vao_batch.second) {
                    material.transform(transform->getMatrix());
                    if (vao.hasIndices())
                        glDrawElements(option.primitive_type, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
                    else
                        glDrawArrays(option.primitive_type,0,vao.getVertexCount());
                }
                vao.unbind();
            }
            material.unbind();
        }
    }
    batches.clear();
    buffer.unbind();
}
void BatchRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat)const  {
    Log::message("depth");

    buffer.bind();
    clearDepth();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    DEPTH_SHADER.bind();
    DEPTH_SHADER.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    for (auto option_batch:batches) {
        const RenderOption& option=option_batch.first;
        option.cull_faces?glEnable(GL_CULL_FACE):glDisable(GL_CULL_FACE);
        option.depth_test?glEnable(GL_DEPTH_TEST):glDisable(GL_CULL_FACE);
        for (auto &vao_batch:option_batch.second) {
            for (auto &transform_batch:vao_batch.second) {
                const VAO &vao = *transform_batch.first;
                vao.bind();
                for (auto &transform_batch:transform_batch.second) {
                    const Transform& transform=*transform_batch;
                    DEPTH_SHADER.loadUniform(depthShader_transform_mat_location,transform.getMatrix());
                    if (vao.hasIndices())
                        glDrawElements(option.primitive_type, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
                    else
                        glDrawArrays(option.primitive_type,0,vao.getVertexCount());
                }
                vao.unbind();
            }
        }
    }

    batches.clear();
    buffer.unbind();

}

void BatchRenderer::draw(const VAO &vao, const EntityMaterial &material, const Transform &transform,RenderOption options) const {
    Log::message("draw");

    if(batches.find(options)==batches.end())
    {
        batches.emplace(options,std::unordered_map<const EntityMaterial *, std::unordered_map<const VAO *, std::list<const Transform*>>>());
    }
    auto options_batch=batches.at(options);

    if (options_batch.find(&material) == options_batch.end()) {
        options_batch.emplace(&material, std::unordered_map<const VAO *, std::list<const Transform *>>());
    }
    auto material_batch=options_batch.at(&material);
    if (material_batch.find(&vao) == material_batch.end()) {
        material_batch.emplace(&vao,std::list<const Transform*>());
    }
    auto vao_batch=material_batch.at(&vao);
    vao_batch.emplace_back(&transform);
}


















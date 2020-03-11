#define GLEW_STATIC

#include <GL/glew.h>
#include "BatchRenderer.h"
#include "Ressources/VAO.h"
#include "Shaders/EntityMaterial.h"
#include "Entities/Transform.h"
#include "Core/Log.h"
#include "Core/Scene.h"

#include "Core/Rendering/FBO.h"

void BatchRenderer::render(const FBO &buffer, const mat4 &projection, const mat4 &view_mat) const {
    Log::message("render");
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());

    buffer.bind();
    for (auto &vao_batch:batches) {
        const EntityMaterial &material = *vao_batch.first;
        material.bind();
        material.projection(projection);
        material.view(view_mat);
        for (auto &transform_batch:vao_batch.second) {
            const VAO &vao = *transform_batch.first;
            vao.bind();
            for (auto &draw_info:transform_batch.second) {
                const Transform& transform=*std::get<0>(draw_info);
                int primitive=std::get<1>(draw_info);
                bool cull_faces=std::get<2>(draw_info);


                if(cull_faces)
                {
                    glEnable(GL_CULL_FACE);
                    glCullFace(GL_BACK);
                } else{
                    glDisable(GL_CULL_FACE);
                }
                if (vao.hasIndices())
                    glDrawElements(primitive, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
                else
                    glDrawArrays(primitive,0,vao.getVertexCount());
            }
            vao.unbind();
        }
        material.unbind();
    }
    batches.clear();
    buffer.unbind();
}
void BatchRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat)const  {
    Log::message("depth");
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());

    DEPTH_SHADER.bind();
    DEPTH_SHADER.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    for (auto &vao_batch:batches) {
        for (auto &transform_batch:vao_batch.second) {
            const VAO &vao = *transform_batch.first;
            vao.bind();
            for (auto &draw_info:transform_batch.second) {
                const Transform& transform=*std::get<0>(draw_info);
                int primitive=std::get<1>(draw_info);
                bool cull_faces=std::get<2>(draw_info);
                if(cull_faces)
                {
                    glEnable(GL_CULL_FACE);
                    glCullFace(GL_BACK);
                } else{
                    glDisable(GL_CULL_FACE);
                }
                DEPTH_SHADER.loadUniform(depthShader_transform_mat_location, transform.getMatrix());
                glDrawElements(primitive, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
            }
            vao.unbind();
        }
    }
    batches.clear();
    DEPTH_SHADER.unbind();
    buffer.unbind();
}

void BatchRenderer::draw(const VAO &vao, const EntityMaterial &material, const Transform &transform,RenderOption options) const {
    Log::message("draw");
    if (batches.find(&material) == batches.end()) {
        batches.insert(
                std::make_pair(&material, std::unordered_map<const VAO *, std::list<std::tuple<const Transform *,int,bool>>>()));
    }
    std::unordered_map<const VAO *, std::list<std::tuple<const Transform *,int,bool >>> &vao_batch = batches.at(&material);
    if (vao_batch.find(&vao) == vao_batch.end()) {
        vao_batch.insert(std::make_pair(&vao, std::list<std::tuple<const Transform *,int ,bool>>()));
    }
    std::list<std::tuple<const Transform *,int ,bool>> &transform_batch = vao_batch.at(&vao);
    transform_batch.emplace_back(&transform,primitive,cull_faces);
}


















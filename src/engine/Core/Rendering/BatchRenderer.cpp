#define GLEW_STATIC

#include <GL/glew.h>
#include "BatchRenderer.h"
#include "Ressources/VAO.h"
#include "Shaders/Spacial/SpacialMaterial.h"
#include "Entities/Spacial/Transform.h"
#include "Core/Log.h"
#include "Core/Scene.h"



void BatchRenderer::renderSpace(const FBO &buffer, const mat4 &projection, const mat4 &view_mat) const {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    buffer.bind();
    for (auto &vao_batch:spacial_material_batch) {
        const SpacialMaterial &material = *vao_batch.first;
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
    spacial_material_batch.clear();
    buffer.unbind();
}
void BatchRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat)const  {
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());

    DEPTH_SHADER.bind();
    DEPTH_SHADER.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    for (auto &vao_batch:spacial_material_batch) {
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
    spacial_material_batch.clear();
    DEPTH_SHADER.unbind();
    buffer.unbind();
}

void BatchRenderer::draw(const VAO &vao, const SpacialMaterial &material, const Transform &transform,int primitive,bool cull_faces) const {
    if (spacial_material_batch.find(&material) == spacial_material_batch.end()) {
        spacial_material_batch.insert(
                std::make_pair(&material, std::unordered_map<const VAO *, std::list<std::tuple<const Transform *,int,bool>>>()));
    }
    std::unordered_map<const VAO *, std::list<std::tuple<const Transform *,int,bool >>> &vao_batch = spacial_material_batch.at(&material);
    if (vao_batch.find(&vao) == vao_batch.end()) {
        vao_batch.insert(std::make_pair(&vao, std::list<std::tuple<const Transform *,int ,bool>>()));
    }
    std::list<std::tuple<const Transform *,int ,bool>> &transform_batch = vao_batch.at(&vao);
    transform_batch.emplace_back(&transform,primitive,cull_faces);
}


















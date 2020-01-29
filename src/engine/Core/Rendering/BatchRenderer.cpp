#define GLEW_STATIC

#include <GL/glew.h>
#include "BatchRenderer.h"
#include "Geometry/VAO.h"
#include "Shaders/Material.h"
#include "Core/Window.h"
#include "Entities/Transform.h"
#include "Core/Log.h"
#include "Core/Scene.h"
#include "Core/Viewport.h"
#include "Entities/Camera.h"


BatchRenderer::BatchRenderer() {
    depthShader_light_space_matrix_location = depthShader.uniformLocation("space");
    depthShader_transform_mat_location = depthShader.uniformLocation("transform");
}

void BatchRenderer::render(const FBO &buffer, const Scene &scene, const glm::mat4 &space_mat) {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    buffer.bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto &vao_batch:material_batch) {
        const Material &material = *vao_batch.first;
        material.bind(scene);
        material.space(space_mat);
        for (auto &transform_batch:vao_batch.second) {
            const VAO &vao = *transform_batch.first;
            vao.bind();
            for (auto &transform:transform_batch.second) {
                material.transform(transform->getMatrix());
                glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
            }
            vao.unbind();
        }
        material.unbind();
    }
    material_batch.clear();

    buffer.unbind();
}


void BatchRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) {
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    depthShader.bind();
    depthShader.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    for (auto &vao_batch:material_batch) {
        for (auto &transform_batch:vao_batch.second) {
            const VAO &vao = *transform_batch.first;
            vao.bind();
            for (auto &transform:transform_batch.second) {
                depthShader.loadUniform(depthShader_transform_mat_location, transform->getMatrix());
                glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
            }
            vao.unbind();
        }
    }
    material_batch.clear();
    depthShader.unbind();
    buffer.unbind();
}

void BatchRenderer::addToRenderQueue(const VAO &vao, const Material &material, const Transform &transform) {
    if (material_batch.find(&material) == material_batch.end()) {
        material_batch.insert(
                std::make_pair(&material, std::unordered_map<const VAO *, std::list<const Transform *>>()));
    }
    std::unordered_map<const VAO *, std::list<const Transform *>> &vao_batch = material_batch.at(&material);
    if (vao_batch.find(&vao) == vao_batch.end()) {
        vao_batch.insert(std::make_pair(&vao, std::list<const Transform *>()));
    }
    std::list<const Transform *> &transform_batch = vao_batch.at(&vao);
    transform_batch.push_back(&transform);
}













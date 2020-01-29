#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "Geometry/VAO.h"
#include "Shaders/Material.h"
#include "Window.h"
#include "Entities/Transform.h"
#include "Log.h"
#include "Core/Scene.h"
#include "Core/Viewport.h"
#include "Entities/Camera.h"


Renderer::Renderer(Window &window) {
    this->window = &window;
    depthShader_light_space_matrix_location=depthShader.uniformLocation("space");
    depthShader_transform_mat_location=depthShader.uniformLocation("transform");
}

Renderer::~Renderer() {

}


void Renderer::draw(const Texture& texture,const VAO& quad) {
    glClear(GL_COLOR_BUFFER_BIT);
    screenShader.bind();
    quad.bind();
    texture.bind();
    glDrawElements(GL_TRIANGLES,quad.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    texture.unbind();
    quad.unbind();
    screenShader.unbind();
}

void Renderer::render(const FBO &buffer, const Scene &scene, const glm::mat4 &space_mat) {
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


void Renderer::renderDepth(const FBO &buffer,const  glm::mat4& depth_space_mat) {
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

void Renderer::addToRenderQueue(const Material &material, const VAO &vao, const Transform &transform) {
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

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() {
    glClear(GL_COLOR_BUFFER_BIT );
}











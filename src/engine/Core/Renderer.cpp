#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "Geometry/VAO.h"
#include "Shaders/Material.h"
#include "Window.h"
#include "Entities/Transform.h"
#include "Log.h"
#include "Core/Scene.h"
#include "Entities/Camera.h"
Renderer::Renderer(Window &window, Renderer::RenderMode mode) {
    this->window = &window;
    Geometry::make_quad(quad);
    setRenderMode(window.getWidth(), window.getHeight(), mode);
    window.subscribeSizeChange(*this);
    depthShader_light_space_matrix_location=depthShader.uniformLocation("space_matrix");
    depthShader_transform_mat_location=depthShader.uniformLocation("transform");
}

Renderer::Renderer(Window &window) {
    this->window = &window;
    Geometry::make_quad(quad);
    setRenderMode(window.getWidth(), window.getHeight(), currentRenderMode);
    window.subscribeSizeChange(*this);
    depthShader_light_space_matrix_location=depthShader.uniformLocation("space_matrix");
    depthShader_transform_mat_location=depthShader.uniformLocation("transform");
}

Renderer::~Renderer() {
    window->unsubscribeSizeChange(*this);
}


void Renderer::draw(const FBO &buffer) {
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    screenShader.bind();
    quad.bind();
    buffer.getTexture().bind();
    glDrawElements(GL_TRIANGLES, quad.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    buffer.getTexture().unbind();
    quad.unbind();
    screenShader.unbind();
}
void Renderer::render(const Scene &scene) {
    render(scene.getFBO(),scene,scene.getCamera().getCameraSpaceMatrix());
}

void Renderer::render(const FBO &buffer, const Scene &scene, const glm::mat4 &space_mat) {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    scene.render();
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


void Renderer::renderDepth(const FBO &buffer, const Scene &scene, const  glm::mat4& depth_space_mat) {
    glEnable(GL_DEPTH_TEST);
    scene.render();
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
void Renderer::setRenderMode(int width, int height, RenderMode renderMode) {
    currentRenderMode = renderMode;
    float w = (float) width;
    float h = (float) height;
    double aspect_ratio = w / h;
    if (renderMode == PERSPECTIVE) {
        fov = 90;
        projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
    } else if (renderMode == ORTHOGRAPHIC_PIXEL) {
        projection_matrix = glm::ortho<float>(0, width, 0, height, -100, 100);
    } else {
        projection_matrix = glm::ortho<float>(-1, 1, -1 * aspect_ratio, 1 * aspect_ratio, -100, 100);
    }
}
float Renderer::getFOV() const {
    return fov;
}
void Renderer::onViewportSizeChange(int width, int height) {
    setRenderMode(width, height, currentRenderMode);
}









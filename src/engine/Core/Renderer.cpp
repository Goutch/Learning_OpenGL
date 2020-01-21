#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "Entities/MeshRenderer.h"
#include "Geometry/VAO.h"
#include "Shaders/Material.h"
#include "Window.h"
#include "Entities/Transform.h"
#include "Log.h"
#include "Core/Scene.h"
void Renderer::render(const Scene& scene) {
    mat4 viewMat = cam != nullptr ? glm::inverse(cam->getMatrix()) : mat4();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto &vao_batch:material_batch) {
        const Material &material = *vao_batch.first;
        material.bind(scene);
        material.projection(projection_matrix);
        material.view(viewMat);
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
}

void Renderer::addToRenderQueue(Material& material,VAO& vao,Transform& transform) {

    if (material_batch.find(&material) == material_batch.end()) {
        material_batch.insert(std::make_pair(&material, std::unordered_map<VAO *, std::list<Transform *>>()));
    }
    std::unordered_map<VAO *, std::list<Transform *>> &vao_batch = material_batch.at(&material);
    if (vao_batch.find(&vao) == vao_batch.end()) {
        vao_batch.insert(std::make_pair(&vao, std::list<Transform *>()));
    }
    std::list<Transform *> &transform_batch = vao_batch.at(&vao);
    transform_batch.push_back(&transform);

}

Renderer::Renderer(Window &window, Renderer::RenderMode mode) {
    setRenderMode(window, mode);
}

Renderer::~Renderer() {

}

void Renderer::setRenderMode(Window &window, Renderer::RenderMode renderMode) {
    float w = (float) window.getHeight();
    float h = (float) window.getWidth();
    aspect_ratio = w / h;

    if (renderMode == PERSPECTIVE) {
        fov = 90;
        projection_matrix = glm::perspective<float>(glm::radians(fov), h / w, 0.1f, 200.0f);
    } else if(renderMode==ORTHOGRAPHIC_PIXEL) {
        projection_matrix=glm::ortho<float>(-w/2,w/2,-w*aspect_ratio/2,w*aspect_ratio/2,-100,100);
    } else
    {
        projection_matrix = glm::ortho<float>(-1, 1, -1 * aspect_ratio, 1 * aspect_ratio, -100, 100);
    }

}

void Renderer::setCamera(Transform &camera) {
    cam = &camera;
}

float Renderer::getFOV() {
    return fov;
}

float Renderer::getAspectRatio() {
    return aspect_ratio;
}





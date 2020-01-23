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
#include "Utils/TimeUtils.h"

Renderer::Renderer(Window &window, Renderer::RenderMode mode) {
    Geometry::make_quad(quad);
    setRenderMode(window.getWidth(),window.getHeight(), mode);
    window.subscribeSizeChange(*this);
    frame_buffer.setSize(window.getWidth(),window.getHeight());
}
Renderer::Renderer(Window &window) {
    setRenderMode(window.getWidth(),window.getHeight(),currentRenderMode);
    Geometry::make_quad(quad);
    window.subscribeSizeChange(*this);
    frame_buffer.setSize(window.getWidth(),window.getHeight());
}
Renderer::~Renderer() {

}
void Renderer::render(const Scene& scene) {
    glEnable(GL_DEPTH_TEST);
    frame_buffer.bind();
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
    frame_buffer.unbind();

    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    screenShader.bind();
    quad.bind();
    frame_buffer.getTexture().bind();
    glDrawElements(GL_TRIANGLES, quad.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    frame_buffer.getTexture().unbind();
    quad.unbind();
    screenShader.unbind();
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



void Renderer::setRenderMode(int width, int height,RenderMode renderMode) {
    currentRenderMode=renderMode;
    float w = (float) width;
    float h = (float) height;
    aspect_ratio=w/h;
    if (renderMode == PERSPECTIVE) {

        fov = 90;
        projection_matrix = glm::perspective<float>(glm::radians(fov), aspect_ratio, 0.1f, 200.0f);
    } else if(renderMode==ORTHOGRAPHIC_PIXEL) {
        projection_matrix=glm::ortho<float>(0,width,0,height,-100,100);
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

void Renderer::onWindowSizeChange(int width, int height) {
    frame_buffer.setSize(width, height);
    setRenderMode(width,height,currentRenderMode);
}

const Texture &Renderer::getFrameBufferTexture() {
    return frame_buffer.getTexture();
}

void Renderer::screenshot() const {
    frame_buffer.getTexture().save("../screenshot/" + TimeUtils::getTimeString() + ".png");
}


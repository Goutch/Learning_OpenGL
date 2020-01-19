#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "Entities/MeshRenderer.h"
#include "Geometry/VAO.h"
#include "Shaders/Material.h"
#include "Window.h"
#include "Entities/Transform.h"
void Renderer::render() {
    mat4 viewMat = cam != nullptr ? glm::inverse(cam->getMatrix()) : mat4();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    for (auto &e:entities) {
        e->material().bind();
        e->material().projection(projection_matrix);
        e->material().view(viewMat);
        e->material().transform(e->transform.getMatrix());
        e->getVAO().bind();
        glDrawElements(GL_TRIANGLES, e->getVAO().getVertexCount(), GL_UNSIGNED_INT, nullptr);
        e->getVAO().unbind();
        e->material().unbind();
    }
    entities.clear();
}

void Renderer::addToRenderQueue( MeshRenderer& entity) {
    entities.push_back(& entity);
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
        fov=90;
        projection_matrix=glm::perspective<float>(glm::radians(fov), h / w, 0.1f, 100.0f);
    } else {

        projection_matrix=glm::ortho<float>(-1, 1, -1 * aspect_ratio, 1 * aspect_ratio, -100, 100);
        //projection_matrix=glm::ortho<float>(-w/2,w/2,-w*aspect_ratio/2,w*aspect_ratio/2);
    }

}

void Renderer::setCamera(Transform& camera) {
    cam = &camera;
}

float Renderer::getFOV() {
    return fov;
}

float Renderer::getAspectRatio() {
    return aspect_ratio;
}



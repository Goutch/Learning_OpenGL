#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "entities/Entity.h"
#include "graphics/data/VAO.h"
#include "graphics/shaders/EntityShader.h"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"
#include "entities/Camera.h"

void Renderer::render() {
    mat4 viewMat = cam != nullptr ? cam->getViewMatrix() : mat4();
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto &e:entities) {
        e->getShader().bind();
        e->getShader().loadProjectionMatrix(projection_matrix);
        e->getShader().loadViewMatrix(viewMat);
        e->getShader().loadEntityUniforms(*e);
        e->getVAO().bind();
        glDrawElements(GL_QUADS, e->getVAO().getVertexCount(), GL_UNSIGNED_INT, nullptr);
        e->getVAO().unbind();
        e->getShader().unbind();
    }
    entities.clear();
}

void Renderer::addToRenderQueue(Entity *entity) {
    entities.push_back(entity);
}

Renderer::Renderer(Window &window, Renderer::RenderMode mode) {
    setRenderMode(window, mode);
}

Renderer::~Renderer() {

}

void Renderer::setRenderMode(Window &window, Renderer::RenderMode renderMode) {
    float w = (float) window.getHeight();
    float h = (float) window.getWidth();

    if (renderMode == PERSPECTIVE) {
        projection_matrix.copy(glm::value_ptr(glm::perspective<float>(glm::radians(90.0f), h / w, 0.1f, 100.0f)));
    } else {
        float aspect_ratio = w / h;
        projection_matrix.copy(
                glm::value_ptr(glm::ortho<float>(-1, 1, -1 * aspect_ratio, 1 * aspect_ratio, -100, 100)));
        //projection_matrix=glm::ortho<float>(-w/2,w/2,-w*aspect_ratio/2,w*aspect_ratio/2);
    }

}

void Renderer::setCamera(Camera *camera) {
    this->cam = camera;
}



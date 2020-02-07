
#define GLEW_STATIC

#include "Renderer.h"
#include <GL/glew.h>

#include <Geometry/VAO.h>
#include <Shaders/Canvas/CanvasMaterial.h>

#include <Core/Canvas.h>
#include <Data/FBO.h>

Renderer::Renderer() {
    depthShader_light_space_matrix_location = DEPTH_SHADER.uniformLocation("space");
    depthShader_transform_mat_location = DEPTH_SHADER.uniformLocation("transform");
}

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth()const  {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderOnMainBuffer(const Canvas& canvas) {
    glDisable(GL_DEPTH_TEST);
    canvas.getMaterial().bind();
    canvas.getVAO().bind();
    canvas.getMaterial().transform(canvas.transform.getMatrix());
    canvas.getMaterial().projection(canvas.getPixelProjection());
    glDrawElements(GL_TRIANGLES, QUAD_CENTER.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    canvas.getVAO().unbind();
    canvas.getMaterial().unbind();
}

void Renderer::renderCanvas(const FBO &buffer, const mat4 &projection)const  {
    glDisable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    while (!canvas_elements.empty()) {
        CanvasElement& canvas_element = canvas_elements.front();
        canvas_element.material->bind();
        canvas_element.material->transform(canvas_element.transform->getMatrix());
        canvas_element.material->projection(projection);
        canvas_element.vao->bind();
        glDrawElements(GL_TRIANGLES, canvas_element.vao->getVertexCount(), GL_UNSIGNED_INT, nullptr);
        canvas_element.vao->unbind();
        canvas_element.material->unbind();
        canvas_elements.pop();
    }
    buffer.unbind();
}
void Renderer::draw(const VAO &vao, const CanvasTransform &transform, const CanvasMaterial &material) const {
    canvas_elements.emplace(transform,material,vao);
}


void Renderer::wireframe(bool enable) {
    enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}






















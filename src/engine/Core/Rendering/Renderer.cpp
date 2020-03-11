

#include "Renderer.h"

#define GLEW_STATIC

#include "GL/glew.h"


#include <Core/Canvas.h>


const int Renderer::PRIMITIVE_TRIANGLES = GL_TRIANGLES;
const int Renderer::PRIMITIVE_POINTS = GL_POINTS;

Renderer::Renderer() {
    depthShader_light_space_matrix_location = DEPTH_SHADER.uniformLocation("space");
    depthShader_transform_mat_location = DEPTH_SHADER.uniformLocation("transform");
    glClearColor(0.4, 0.4, 0.7, 1);

}

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth() const {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderOnMainBuffer(const Canvas &canvas) {
    glDisable(GL_DEPTH_TEST);
    canvas.getMaterial().bind();
    canvas.getVAO().bind();
    canvas.getMaterial().transform(canvas.transform.getMatrix());
    canvas.getMaterial().projection(canvas.getPixelProjection());
    glDrawElements(GL_TRIANGLES, canvas.getVAO().getVertexCount(), GL_UNSIGNED_INT, nullptr);
    canvas.getVAO().unbind();
    canvas.getMaterial().unbind();
}

void Renderer::wireframe(bool enable) {
    enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}






















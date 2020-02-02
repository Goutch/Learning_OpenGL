
#define GLEW_STATIC

#include "Renderer.h"
#include <GL/glew.h>
#include "Shaders/Shader.h"
#include <Data/Texture.h>
#include <Geometry/VAO.h>
#include "Shaders/Material.h"
#include <math.h>
Renderer::Renderer() {
    depthShader_light_space_matrix_location = DEPTH_SHADER.uniformLocation("space");
    depthShader_transform_mat_location = DEPTH_SHADER.uniformLocation("transform");
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const VAO &vao) {
    draw(vao, DEFAULT_MATERIAL, DEFAULT_TRANSFORM);
}

void Renderer::draw(const VAO &vao, const Material &material) {
    draw(vao, material, DEFAULT_TRANSFORM);
}

void Renderer::draw(const VAO &vao, const Transform &transform) {
    draw(vao, DEFAULT_MATERIAL, transform);
}

void Renderer::draw(const VAO &vao, const Shader &shader, const Texture &texture) {
    glDisable(GL_DEPTH_TEST);
    shader.bind();
    vao.bind();
    texture.bind();
    glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    texture.unbind();
    vao.unbind();
    shader.unbind();
}
void Renderer::drawRect(float x, float y, float width, float height,const Color& color) {
    glDisable(GL_DEPTH_TEST);
    Transform transform(vec3(x,y,0),vec3(0),vec3(width,height,1));
    primitive_material.shader(DEFAULT_SHADER);
    primitive_material.color(color);
    primitive_material.bind();
    primitive_material.transform(transform.getMatrix());
    primitive_material.view(mat4(1.0f));
    primitive_material.projection(mat4(1.0f));

    QUAD.bind();
    glDrawElements(GL_TRIANGLES,QUAD.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    QUAD.unbind();
    primitive_material.unbind();
   // primitives_queue.emplace(Transform(vec3(x,y,0),vec3(0),vec3(1)),color,DEFAULT_SHADER);
}

void Renderer::drawEllipse(float x, float y, float width, float height,const Color& color) {
    glDisable(GL_DEPTH_TEST);
    Transform transform(vec3(x,y,0),vec3(0),vec3(width,height,1));
    primitive_material.shader(ELLIPSE_SHADER);
    primitive_material.color(color);
    primitive_material.bind();
    primitive_material.transform(transform.getMatrix());
    primitive_material.view(mat4(1.0f));
    primitive_material.projection(mat4(1.0f));
    QUAD.bind();
    glDrawElements(GL_TRIANGLES,QUAD.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    QUAD.unbind();
    primitive_material.unbind();
    //primitives_queue.emplace(Transform(vec3(x,y,0),vec3(0),vec3(1)),color,ELLIPSE_SHADER);
}
void Renderer::drawLine(float x1, float y1, float x2, float y2, float width,const Color& color) {
    float deltaX=x2-x1;
    float deltaY=y2-y1;
    float x=x1+(deltaX/2);
    float y=y1+(deltaY/2);
    float lenght=(float)sqrt((deltaX*deltaX)+(deltaY*deltaY))+(width*2);
    float rot=atan(deltaY,deltaX);
    glDisable(GL_DEPTH_TEST);
    Transform transform(vec3(x,y,0),vec3(0,0,rot),vec3(lenght,width,1));
    primitive_material.shader(DEFAULT_SHADER);
    primitive_material.color(color);
    primitive_material.bind();
    primitive_material.transform(transform.getMatrix());
    primitive_material.view(mat4(1.0f));
    primitive_material.projection(mat4(1.0f));
    QUAD.bind();
    glDrawElements(GL_TRIANGLES,QUAD.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    QUAD.unbind();
    primitive_material.unbind();
    //primitives_queue.emplace(Transform(vec3(x,y,0),vec3(0,0,rot),vec3(lenght,width,1)),color,DEFAULT_SHADER);
}

void Renderer::wireframe(bool enable) {
    enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}










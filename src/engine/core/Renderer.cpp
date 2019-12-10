#define GLEW_STATIC

#include <GL/glew.h>
#include "Renderer.h"
#include "entities/Entity.h"
#include "graphics/Drawable.h"
#include "graphics/shaders/BaseShader.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Window.h"
void Renderer::render() {

    glClear(GL_COLOR_BUFFER_BIT);
    for(auto &e:entities)
    {
        e->getShader().bind();
        e->getShader().loadProjectionMatrix(projection_matrix);
        e->getShader().loadEntityUniforms(*e);
        e->getDrawable().bind();
        glDrawElements(GL_QUADS, e->getDrawable().vertexCount(), GL_UNSIGNED_INT, nullptr);
        e->getDrawable().unbind();
        e->getShader().unbind();
    }
    entities.clear();
}

void Renderer::addToRenderQueue(Entity* entity) {
    entities.push_back(entity);
}

Renderer::Renderer(Window &window, Renderer::RenderMode mode) {
    setRenderMode(window,mode);
}

Renderer::~Renderer() {

}

void Renderer::setRenderMode(Window& window,Renderer::RenderMode renderMode) {
    float w=(float)window.getHeight();
    float h=(float)window.getWidth();

    if(renderMode==PERSPECTIVE)
    {
        projection_matrix= glm::perspective<float>(glm::radians(90.0f), h/w, 0.1f, 100.0f);
    }
    else{
        float aspect_ratio=w/h;
        projection_matrix=glm::ortho<float>(-1,1,-1*aspect_ratio,1*aspect_ratio,-100,100);
        //projection_matrix=glm::ortho<float>(-w/2,w/2,-w*aspect_ratio/2,w*aspect_ratio/2);
    }

}



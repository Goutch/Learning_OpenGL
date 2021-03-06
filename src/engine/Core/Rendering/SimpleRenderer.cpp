
#define GLEW_STATIC

#include <GL/glew.h>
#include "SimpleRenderer.h"
#include <Ressources/Shaders/Material/EntityMaterial.h>
#include <Core/Rendering/FBO.h>
#include "Ressources/VAO.h"
#include <Entities/Transform.h>

void SimpleRenderer::draw(const VAO &vao, const EntityMaterial &material, const Transform& transform,RenderOption options)const  {
    render_queue.emplace(&material,&vao,&transform,options);
}

void SimpleRenderer::render(const FBO &buffer, const mat4 &projection, const mat4 &view_mat) const {
    buffer.bind();
    clear();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    while(!render_queue.empty()) {
        std::tuple<const EntityMaterial*,const VAO*,const Transform *,RenderOption>& renderableObject=render_queue.front();
        const EntityMaterial& material=*std::get<0>(renderableObject);
        const VAO& vao=*std::get<1>(renderableObject);
        const Transform& transform=*std::get<2>(renderableObject);
        RenderOption options=std::get<3>(renderableObject);
        options.cull_faces?glEnable(GL_CULL_FACE):glDisable(GL_CULL_FACE);
        options.depth_test?glEnable(GL_DEPTH_TEST):glDisable(GL_CULL_FACE);

        material.bind();
        material.projection(projection);
        material.view(view_mat);
        material.transform(transform.getMatrix());
        vao.bind();
        if (vao.hasIndices())
            glDrawElements(options.primitive_type, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
        else
            glDrawArrays(options.primitive_type,0,vao.getVertexCount());
        vao.unbind();
        material.unbind();

        render_queue.pop();
    }
    buffer.unbind();

}

void SimpleRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) const {
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    clearDepth();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    DEPTH_SHADER.bind();
    DEPTH_SHADER.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    while(!render_queue.empty()) {
        std::tuple<const EntityMaterial*,const VAO*,const Transform *,RenderOption>& renderableObject=render_queue.front();
        const EntityMaterial& material=*std::get<0>(renderableObject);
        const VAO& vao=*std::get<1>(renderableObject);
        const Transform& transform=*std::get<2>(renderableObject);
        RenderOption options=std::get<3>(renderableObject);
        options.cull_faces?glEnable(GL_CULL_FACE):glDisable(GL_CULL_FACE);
        DEPTH_SHADER.loadUniform(depthShader_transform_mat_location, transform.getMatrix());
        vao.bind();
        if (vao.hasIndices())
            glDrawElements(options.primitive_type, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
        else
            glDrawArrays(options.primitive_type,0,vao.getVertexCount());
        vao.unbind();
        render_queue.pop();
    }
    DEPTH_SHADER.unbind();

    buffer.unbind();

}







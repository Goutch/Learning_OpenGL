
#define GLEW_STATIC
#include <GL/glew.h>
#include "EntityShader.h"
#include "entities/Entity.h"
EntityShader::EntityShader() : ShaderProgram("../src/engine/graphics/shaders/shadersSources/EntityVertex.glsl",
                                             "../src/engine/graphics/shaders/shadersSources/EntityFragment.glsl") {
    getUniformsLocations();
}

void EntityShader::loadEntityUniforms(Entity &e) {

        loadMat4Uniform(transform_location, e.transform.getMatrix());
        //todo:move to material
        loadIntUniform(texture_0_location,0);
        loadIntUniform(has_texture_location,0);
}

void EntityShader::getUniformsLocations() {

    transform_location =glGetUniformLocation(program_id,"transform");
    texture_0_location=glGetUniformLocation(program_id,"texture_0");
    has_texture_location=glGetUniformLocation(program_id,"has_texture");
    projection_mat_location=glGetUniformLocation(program_id,"projection_mat");
    view_mat_location=glGetUniformLocation(program_id,"view_mat");
}

void EntityShader::loadViewMatrix(const mat4 &view_mat) {
    loadMat4Uniform(view_mat_location,view_mat);
}

void EntityShader::loadProjectionMatrix(const mat4 &projection_mat) {
    loadMat4Uniform(projection_mat_location,projection_mat);
}

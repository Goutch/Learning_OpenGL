
#define GLEW_STATIC
#include <GL/glew.h>
#include "BaseShader.h"
#include "entities/Entity.h"
BaseShader::BaseShader() : ShaderProgram("../src/engine/graphics/shaders/shadersSources/BaseVertex.glsl",
                                         "../src/engine/graphics/shaders/shadersSources/BaseFragment.glsl") {
    getUniformsLocations();
}

void BaseShader::loadEntityUniforms(Entity &e) {

        loadMat4Uniform(transform_location, e.transform.toMatrix());
        //todo:move to material
        loadIntUniform(texture_0_location,0);
        loadIntUniform(has_texture_location,0);
}

void BaseShader::getUniformsLocations() {

    transform_location =glGetUniformLocation(program_id,"transform");
    texture_0_location=glGetUniformLocation(program_id,"texture_0");
    has_texture_location=glGetUniformLocation(program_id,"has_texture");
    projection_mat_location=glGetUniformLocation(program_id,"projection_mat");
}

void BaseShader::loadProjectionMatrix(glm::mat4 &projection_mat) {
    loadMat4Uniform(projection_mat_location,projection_mat);
}

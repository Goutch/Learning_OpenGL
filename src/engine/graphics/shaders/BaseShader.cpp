
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
        loadIntUniform(texture_location,0);
        loadIntUniform(1,1);
}

void BaseShader::getUniformsLocations() {

    transform_location =glGetUniformLocation(program_id,"transform");
    texture_location=glGetUniformLocation(program_id,"texture_0");
    has_texture_location=glGetUniformLocation(program_id,"has_texture");
}

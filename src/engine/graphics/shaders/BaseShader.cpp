
#define GLEW_STATIC
#include <GL/glew.h>
#include "BaseShader.h"
#include "entities/Entity.h"
#include "iostream"
BaseShader::BaseShader() : ShaderProgram("../src/engine/graphics/shaders/shadersSources/BaseVertex.glsl",
                                         "../src/engine/graphics/shaders/shadersSources/BaseFragment.glsl") {
    getUniformsLocations();
}

void BaseShader::loadEntityUniforms(Entity &e) {

        loadMat4Uniform(transform_location, e.transform.toMatrix());
        loadIntUniform(texture_location,0);
        loadIntUniform(second_tex_location,1);
}

void BaseShader::getUniformsLocations() {

    transform_location =glGetUniformLocation(program_id,"transform");
    if(transform_location==-1)
    {
        std::cout<<"FAILED to get uniform location of transform";
    }
    texture_location=glGetUniformLocation(program_id,"texture_0");
    second_tex_location=glGetUniformLocation(program_id,"texture_1");
}

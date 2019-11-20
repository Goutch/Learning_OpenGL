
#define GLEW_STATIC
#include <GL/glew.h>
#include "BaseShader.h"
#include "entities/Entity.h"

BaseShader::BaseShader() : ShaderProgram("../src/engine/graphics/shaders/shadersSources/BaseVertex.glsl",
                                         "../src/engine/graphics/shaders/shadersSources/BaseFragment.glsl") {
    getUniformsLocations();
}

void BaseShader::loadEntityUniforms(Entity &e) {
    loadMat4Uniform(transform_location, e.getTranform().getTransformMatrix());
}

void BaseShader::getUniformsLocations() {
    transform_location =glGetUniformLocation(program_id,"transform");
}

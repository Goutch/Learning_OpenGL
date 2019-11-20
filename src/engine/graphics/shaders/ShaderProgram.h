#pragma once

#include <string>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat2x2.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"

class ShaderProgram {
protected:
    unsigned int program_id;

    unsigned int compileShader(unsigned int type, const std::string &source);

    std::string getSource(const std::string &path);

public:

    void unbind();

    ShaderProgram(const std::string &vertexShader, const std::string &fragmentShader);

    ~ShaderProgram();


    void bind();

protected:
    void loadIntUniform(unsigned int location, int i);

    void loadFloatUniform(unsigned int location, float f);

    void loadVectorUniform(unsigned int location, const glm::vec2 &v);

    void loadVectorUniform(unsigned int location, const glm::vec3 &v);

    void loadVectorUniform(unsigned int location, const glm::vec4 &v);

    void loadMat2Uniform(unsigned int location, const glm::mat2 &m);

    void loadMat3Uniform(unsigned int location, const glm::mat3 &m);

    void loadMat4Uniform(unsigned int location, const glm::mat4 &m);

};


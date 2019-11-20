#pragma once

#include <string>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat2x2.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"

class ShaderProgram {
private:
    unsigned int program_id;

    unsigned int compileShader(unsigned int type, const std::string &source);

    std::string getSource(const std::string &path);

public:
    void bind();

    void unbind();

    ShaderProgram(const std::string &vertexShader, const std::string &fragmentShader);

    ~ShaderProgram();

protected:
    void loadIntUniform(unsigned int location, int i);

    void loadFloatUniform(unsigned int location, float f);

    void loadVectorUniform(unsigned int location, glm::vec2 &v);

    void loadVectorUniform(unsigned int location, glm::vec3 &v);

    void loadVectorUniform(unsigned int location, glm::vec4 &v);

    void loadMattrixUniform(unsigned int location, glm::mat2x2 &m);

    void loadMattrixUniform(unsigned int location, glm::mat3x3 &m);

    void loadMattrixUniform(unsigned int location, glm::mat4x4 &m);


};


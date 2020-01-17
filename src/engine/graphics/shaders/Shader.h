#pragma once

#include <string>
#include "glm/glm.hpp"
#include <unordered_map>
#include <vector>

using namespace glm;

class Shader {
private:
    unsigned int compileShader(unsigned int type, const std::string &source);

    std::string getSource(const std::string &path);

protected:
    std::unordered_map<std::string, unsigned int> uniforms;

    unsigned int program_id;

    int uniformLocation(std::string) ;

public:

    Shader(const std::string &vertexShader, const std::string &fragmentShader);

    ~Shader();

    void bind() const;

    void unbind() const;

    void addUniform(std::string);

    std::vector<std::string> getUniforms();

    void loadUniform(std::string name, int i);

    void loadUniform(std::string name, float f);

    void loadUniform(std::string name, const glm::vec2 &v);

    void loadUniform(std::string name, const glm::vec3 &v);

    void loadUniform(std::string name, const glm::vec4 &v);

    void loadUniform(std::string name, const glm::mat3 &m);

    void loadUniform(std::string name, const glm::mat4 &m);

};


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

    mutable std::unordered_map<std::string,int> uniforms;

    unsigned int program_id;

public:

    Shader(const std::string &vertexShader, const std::string &fragmentShader);

    ~Shader();

    void bind() const;

    void unbind() const;

    int uniformLocation(std::string) const;

    void loadUniform(std::string name, int i) const;

    void loadUniform(std::string name, float f) const;

    void loadUniform(std::string name, const glm::vec2 &v) const;

    void loadUniform(std::string name, const glm::vec3 &v) const;

    void loadUniform(std::string name, const glm::vec4 &v) const;

    void loadUniform(std::string name, const glm::mat3 &m) const;

    void loadUniform(std::string name, const glm::mat4 &m) const;

    void loadUniform(unsigned int location, int i) const;

    void loadUniform(unsigned int location, float f) const;

    void loadUniform(unsigned int location, const glm::vec2 &v) const;

    void loadUniform(unsigned int location, const glm::vec3 &v) const;

    void loadUniform(unsigned int location, const glm::vec4 &v) const;

    void loadUniform(unsigned int location, const glm::mat3 &m) const;

    void loadUniform(unsigned int location, const glm::mat4 &m) const;
};


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

    mutable std::unordered_map<std::string, int> uniforms;

    unsigned int program_id;

public:

    Shader(const std::string &vertexShader, const std::string &fragmentShader,bool source=false);

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

    void loadUniformIntArray(unsigned int location, int *i, unsigned int count) const;

    void loadUniformFloatArray(unsigned int location, float *f, unsigned int count) const;

    void loadUniformVec2Array(unsigned int location, const glm::vec2 *v, unsigned int count) const;

    void loadUniformVec3Array(unsigned int location, const glm::vec3 *v, unsigned int count) const;

    void loadUniformVec4Array(unsigned int location, const glm::vec4 *v, unsigned int count) const;

};


#pragma once

class Shader;

class Texture;

#include <string>
#include <unordered_map>
#include "graphics/shaders/Shader.h"

using namespace glm;

class Material {
private:
    bool has_transparency;
    bool has_texture;
    Texture *t;
    Shader *s;
public:
    Material();
    Material(Shader& shader);
    Material(Shader& shader,Texture& texture);
    void bind();

    void unbind();

    const Shader &shader() const;

    void shader(Shader &shader);

    const Texture &texture() const;

    void texture(Texture &texture);

    void uniform(std::string name, bool value);

    void uniform(std::string name, int value);

    void uniform(std::string name, float value);

    void uniform(std::string name, glm::vec2 value);

    void uniform(std::string name, glm::vec3 value);

    void uniform(std::string name, glm::vec4 value);

    void uniform(std::string name, glm::mat3 value);

    void uniform(std::string name, glm::mat4 value);

};



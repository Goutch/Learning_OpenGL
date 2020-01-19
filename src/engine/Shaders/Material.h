#pragma once

class Shader;

class Texture;

#include <string>
#include <unordered_map>
#include "Shaders/Shader.h"

using namespace glm;

class Material {
private:
    bool has_transparency;
    bool has_texture;
    int transform_location,view_location,projection_location,has_texture_location,texture_0_location;

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

    void getUniformsLocations();

    void transform(const mat4& transform);

    void view(const mat4& view);

    void projection(const mat4& projection);



};



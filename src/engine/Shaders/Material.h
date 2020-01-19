#pragma once

class Shader;

class Texture;

#include <string>
#include <unordered_map>
#include <Data/Color.h>
#include "Shaders/Shader.h"

using namespace glm;

class Material {
private:
    bool has_transparency;
    bool has_texture;
    int transform_location, view_location, projection_location, has_texture_location, texture_0_location,material_color_location;
    Color c = Color::WHITE;
    Texture *t;
    Shader *s;
public:
    Material();

    Material(Shader &shader);

    Material(Shader &shader,const Color &color);

    Material(Shader &shader, Texture &texture);

    Material(Shader &shader, Texture &texture,const Color &color);

    void bind() const;

    void unbind() const;

    const Shader &shader() const;

    void shader(Shader &shader);

    const Texture &texture() const;

    void texture(Texture &texture);

    void color(const Color &color);
    const Color &color() const;
    void getUniformsLocations();

    void transform(const mat4 &transform) const;

    void view(const mat4 &view) const;

    void projection(const mat4 &projection)const;


};



#pragma once

class Shader;

class Texture;

#include <string>
#include <unordered_map>
#include <Data/Color.h>
#include "Shaders/Shader.h"

class Scene;

using namespace glm;

class Material {
protected:
    bool has_transparency;
    bool has_texture;
    int transform_location, view_location, projection_location, has_texture_location, texture_0_location, material_color_location;
    Color c = Color::WHITE;
    Texture *t;
    Shader *s;
public:
    Material();

    Material(Shader &shader);

    Material(Shader &shader, const Color &color);

    Material(Shader &shader, Texture &texture);

    Material(Shader &shader, Texture &texture, const Color &color);

    virtual void bind(const Scene &scene) const;

    void unbind() const;

    const Shader &shader() const;

    Material &shader(Shader &shader);

    const Texture &texture() const;

    Material &texture(Texture &texture);

    Material &color(const Color &color);

    const Color &color() const;



    void transform(const mat4 &transform) const;

    void view(const mat4 &view) const;

    void projection(const mat4 &projection) const;

private:
    void getUniformsLocations();

};



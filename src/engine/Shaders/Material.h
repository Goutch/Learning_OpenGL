#pragma once

#include <Data/Color.h>

class Color;

class Shader;

class Material {
    bool shader_initialized=false;
protected:
    const Shader *shader;
    Color color = Color::WHITE;
    mutable int material_color_location;

    virtual void getUniformsLocations() const;

public:
    Material();

    Material(const Shader &shader);

    Material(const Shader &shader, const Color &color);

    virtual void bind() const;

    virtual void unbind() const;

    void setColor(const Color &color);

    const Color &getColor() const;

    const Shader &getShader() const;

    void setShader(const Shader &shader);
};


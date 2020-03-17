#pragma once

#include <Ressources/Color.h>

class Color;

class Shader;

class Material {
    bool shader_initialized=false;
protected:
    const Shader *shader;
    Color color = Color::WHITE;
    mutable int material_color_location;
    bool has_transparency=false;
    virtual void getUniformsLocations() const;

public:
    Material();
    void setTransparent(bool transparent);

    Material(const Shader &shader);

    Material(const Shader &shader, const Color &color);

    virtual void bind() const;

    virtual void unbind() const;

    void setColor(const Color &color);

    const Color &getColor() const;

    const Shader &getShader() const;

    void setShader(const Shader &shader);

    bool hasTransparency() const;
};


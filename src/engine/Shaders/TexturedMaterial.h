#pragma once

class Texture;

#include "Material.h"
class TexturedMaterial:public Material {
protected:
    const Texture *texture;
    int has_texture_location, texture_0_location;
    bool has_texture;
    void getUniformsLocations() override;
public:
    TexturedMaterial();
    TexturedMaterial(const Shader& shader);
    TexturedMaterial(const Shader& shader,const Color color);
    TexturedMaterial(const Shader& shader,const Texture& texture);
    TexturedMaterial(const Shader& shader,const Color color,const Texture& texture);
    const Texture &getTexture() const;
    void setTexture(const Texture &texture);

    void bind() const override;

    void unbind() const override;

};


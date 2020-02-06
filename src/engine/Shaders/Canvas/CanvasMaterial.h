#pragma once


#include <Shaders/TexturedMaterial.h>
#include <glm/glm.hpp>
using namespace glm;
class CanvasMaterial:public TexturedMaterial {
protected:
    mutable int transform_location, projection_mat_location;
protected:
    void getUniformsLocations() const override;

public:

    CanvasMaterial();
    CanvasMaterial(const Shader& shader);
    CanvasMaterial(const Shader& shader,const Color color);
    CanvasMaterial(const Shader& shader,const Texture& texture);
    CanvasMaterial(const Shader& shader,const Color color,const Texture& texture);
    void projection(const mat3 &projection) const;
    void transform(const mat3 &transform) const;

};

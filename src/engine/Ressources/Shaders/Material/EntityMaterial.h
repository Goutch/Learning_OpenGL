#pragma once

#include <string>
#include <unordered_map>
#include <Ressources/Color.h>
#include <glm/glm.hpp>
#include <Ressources/Shaders/Material/TexturedMaterial.h>
#include "Material.h"

class Shader;
class Texture;

class Scene;

using namespace glm;

class EntityMaterial: public TexturedMaterial {
protected:
    mutable int transform_location, view_mat_location,projection_mat_location;

public:
    EntityMaterial();

    EntityMaterial(const Shader &shader);

    EntityMaterial(const Shader &shader, const Color &color);

    EntityMaterial(const Shader &shader, const Texture &texture);

    EntityMaterial(const Shader &shader, const Texture &texture, const Color &color);

    virtual void bind() const override ;

    virtual void unbind() const override ;

protected:
    void getUniformsLocations() const override;

public:
    void projection(const mat4 &projection) const;
    void transform(const mat4 &transform) const;
    void view(const mat4 &view) const;

};



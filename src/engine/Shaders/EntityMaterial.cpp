//
// Created by User on 16-Jan.-2020.
//

#include "EntityMaterial.h"
#include "Core/Scene.h"
#include "Ressources/Texture.h"
#include <Shaders/Shader.h>
EntityMaterial::EntityMaterial(): TexturedMaterial() {

}

EntityMaterial::EntityMaterial(const Shader &shader): TexturedMaterial(shader) {

}

EntityMaterial::EntityMaterial(const Shader &shader, const Color &color): TexturedMaterial(shader, color) {


}

EntityMaterial::EntityMaterial(const Shader &shader, const  Texture &texture): TexturedMaterial(shader, texture) {

}

EntityMaterial::EntityMaterial(const Shader &shader, const Texture &texture, const Color &color): TexturedMaterial(shader, color, texture) {

}

void EntityMaterial::bind() const{
    TexturedMaterial::bind();
}

void EntityMaterial::unbind() const{
    TexturedMaterial::unbind();
}

void EntityMaterial::transform(const mat4 &transform) const {
    shader->loadUniform(transform_location, transform);
}

void EntityMaterial::view(const mat4 & view) const{
    shader->loadUniform(view_mat_location, view);
}

void EntityMaterial::projection(const mat4 &projection) const {
    shader->loadUniform(projection_mat_location, projection);
}

void EntityMaterial::getUniformsLocations() const {
    TexturedMaterial::getUniformsLocations();
    transform_location = shader->uniformLocation("transform");
    view_mat_location = shader->uniformLocation("view");
    projection_mat_location=shader->uniformLocation("projection");

}









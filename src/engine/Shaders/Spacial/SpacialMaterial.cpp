//
// Created by User on 16-Jan.-2020.
//

#include "SpacialMaterial.h"
#include "Core/Scene.h"
#include "Data/Texture.h"
#include <Shaders/Shader.h>
SpacialMaterial::SpacialMaterial():TexturedMaterial() {

}

SpacialMaterial::SpacialMaterial(const Shader &shader):TexturedMaterial(shader) {

}

SpacialMaterial::SpacialMaterial(const Shader &shader, const Color &color):TexturedMaterial(shader,color) {


}

SpacialMaterial::SpacialMaterial(const Shader &shader, const  Texture &texture):TexturedMaterial(shader,texture) {

}

SpacialMaterial::SpacialMaterial(const Shader &shader, const Texture &texture, const Color &color):TexturedMaterial(shader,color,texture) {

}

void SpacialMaterial::bind() const{
    TexturedMaterial::bind();
}

void SpacialMaterial::unbind() const{
    TexturedMaterial::unbind();
}

void SpacialMaterial::transform(const mat4 &transform) const {
    shader->loadUniform(transform_location, transform);
}

void SpacialMaterial::view(const mat4 & view) const{
    shader->loadUniform(view_mat_location, view);
}

void SpacialMaterial::projection(const mat4 &projection) const {
    shader->loadUniform(projection_mat_location, projection);
}

void SpacialMaterial::getUniformsLocations() {
    Material::getUniformsLocations();
    transform_location = shader->uniformLocation("transform");
    view_mat_location = shader->uniformLocation("view");
    projection_mat_location=shader->uniformLocation("projection");

}









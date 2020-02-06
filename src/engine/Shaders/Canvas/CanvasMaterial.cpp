//
// Created by User on 05-Feb.-2020.
//

#include "CanvasMaterial.h"
#include <Shaders/Shader.h>

CanvasMaterial::CanvasMaterial() : TexturedMaterial() {

}

CanvasMaterial::CanvasMaterial(const Shader &shader) : TexturedMaterial(shader) {

}

CanvasMaterial::CanvasMaterial(const Shader &shader, const Color color) : TexturedMaterial(shader, color) {

}

CanvasMaterial::CanvasMaterial(const Shader &shader, const Texture &texture) : TexturedMaterial(shader, texture) {

}

CanvasMaterial::CanvasMaterial(const Shader &shader, const Color color, const Texture &texture) : TexturedMaterial(
        shader, color, texture) {

}

void CanvasMaterial::getUniformsLocations() const {
    TexturedMaterial::getUniformsLocations();
    transform_location = shader->uniformLocation("transform");
    projection_mat_location = shader->uniformLocation("projection");
}

void CanvasMaterial::projection(const mat4 &projection) const {
    shader->loadUniform(projection_mat_location, projection);
}

void CanvasMaterial::transform(const mat4 &transform) const {
    shader->loadUniform(transform_location, transform);
}



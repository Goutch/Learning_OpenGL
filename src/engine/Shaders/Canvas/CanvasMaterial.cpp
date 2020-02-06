//
// Created by User on 05-Feb.-2020.
//

#include "CanvasMaterial.h"
#include <Shaders/Shader.h>
CanvasMaterial::CanvasMaterial():TexturedMaterial() {

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
void CanvasMaterial::getUniformsLocations() {
    TexturedMaterial::getUniformsLocations();
}

void CanvasMaterial::projection(const mat3 &projection) const {
    shader->loadUniform(projection_mat_location,projection);
}

void CanvasMaterial::transform(const mat3 &transform) const {
    shader->loadUniform(transform_location,transform);
}



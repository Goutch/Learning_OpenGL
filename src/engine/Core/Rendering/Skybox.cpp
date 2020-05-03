//
// Created by User on 02-May-2020.
//


#include "Skybox.h"
#include <Utils/Geometry.h>

Skybox::Skybox(AtlasTexture &texture,const Shader &shader) {
    Geometry::make_skybox(mesh,texture);
    transform.scale(vec3(50));
    material.setShader(shader);
    material.setTexture(texture);

}

Mesh &Skybox::getMesh() {
    return mesh;
}

EntityMaterial &Skybox::getMaterial() {
    return material;
}

Transform &Skybox::getTransform() {
   return transform;
}

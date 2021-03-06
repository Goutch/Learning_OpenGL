//
// Created by le6mon on 2020-02-01.
//

#include <Ressources/AtlasTexture.h>
#include <Ressources/Shaders/Shader.h>
#include "FontMaterial.h"

FontMaterial::FontMaterial(const Shader &shader, std::string path_to_font_texture, unsigned int width,
                           unsigned int height) : EntityMaterial(shader, *(new AtlasTexture(path_to_font_texture, width, height, true))){

}

FontMaterial::~FontMaterial() {
    delete texture;
}

void FontMaterial::getCoordinates(float (&uvs)[8], unsigned int index) const {
    const AtlasTexture* fontTexture = dynamic_cast<const AtlasTexture*>(texture);
    fontTexture->getCoordinates(uvs, index);
}





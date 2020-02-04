//
// Created by le6mon on 2020-02-01.
//

#include <Data/AtlasTexture.h>
#include "FontMaterial.h"

FontMaterial::FontMaterial(std::string path, unsigned int width, unsigned int height, Shader& shader) : Material(shader, *(new AtlasTexture(path, width, height, false))) {}

FontMaterial::~FontMaterial() {
    delete t;
}

void FontMaterial::getCoordinates(float (&uvs)[8], unsigned int index) const {
    const AtlasTexture* fontTexture = dynamic_cast<const AtlasTexture*>(t);
    fontTexture->getCoordinates(uvs, index);
}

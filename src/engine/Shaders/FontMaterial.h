//
// Created by le6mon on 2020-02-01.
//

#ifndef OGL_ENGINE_FONTMATERIAL_H
#define OGL_ENGINE_FONTMATERIAL_H


#include "Material.h"

class FontMaterial : public Material{
public:
    FontMaterial(std::string path, unsigned int width, unsigned int height, Shader& shader);
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
    virtual ~FontMaterial();
};


#endif //OGL_ENGINE_FONTMATERIAL_H

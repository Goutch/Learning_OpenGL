//
// Created by le6mon on 2020-02-01.
//

#ifndef OGL_ENGINE_FONTTEXT_H
#define OGL_ENGINE_FONTTEXT_H


#include "Material.h"

class FontText : public Material{
public:
    FontText(std::string path, unsigned int width, unsigned int height, Shader& shader);
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
    virtual ~FontText();
};


#endif //OGL_ENGINE_FONTTEXT_H

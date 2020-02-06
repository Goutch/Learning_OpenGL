#pragma once
#include "Shaders/Canvas/CanvasMaterial.h"

class FontMaterial : public CanvasMaterial{
public:
    FontMaterial(const Shader& shader,std::string path_to_font_texture, unsigned int width, unsigned int height);
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
    virtual ~FontMaterial();
};


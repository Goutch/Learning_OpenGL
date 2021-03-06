#pragma once

#include "Ressources/Shaders/Material/EntityMaterial.h"
#include <Ressources/Shaders/Shader.h>
class FontMaterial : public EntityMaterial{
public:
    FontMaterial(const Shader& shader,std::string path_to_font_texture, unsigned int width, unsigned int height);
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
    virtual ~FontMaterial();
};


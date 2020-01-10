#pragma once

#include "Texture.h"

class vec2;

class AtlasTexture : public Texture {
private:
    unsigned int cellWidth;
    unsigned int cellHeight;
public:
    AtlasTexture();

    AtlasTexture(unsigned int cellWidth, unsigned int cellHeight);

    AtlasTexture(std::string path, unsigned int cellWidth, unsigned int cellHeight);

    void setCellSize(unsigned int cellWidth, unsigned int cellHeight);

    void getCoordinatesfloat (float (&uvs)[8],unsigned int row, unsigned int column);
};

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

    AtlasTexture(std::string path, unsigned int cellWidth, unsigned int cellHeight, bool flip_on_load);

    void setCellSize(unsigned int cellWidth, unsigned int cellHeight);

    void getCoordinates(float (&uvs)[8],unsigned int row, unsigned int column) const;
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
};

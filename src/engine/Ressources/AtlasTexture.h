#pragma once

#include "Texture.h"



class AtlasTexture : public Texture {
private:
    unsigned int cellWidth;
    unsigned int cellHeight;
public:
    AtlasTexture();

    AtlasTexture(unsigned int cellWidth, unsigned int cellHeight);

    AtlasTexture(std::string path, unsigned int cellWidth, unsigned int cellHeight, bool flip_on_load);

    void setCellSize(unsigned int cellWidth, unsigned int cellHeight);

    void getCoordinates(float (&uvs)[8],unsigned int column, unsigned int row) const;
    void getCoordinates(float (&uvs)[8],unsigned int index) const;
};

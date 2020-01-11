//
// Created by User on 2020-01-09.
//

#include "AtlasTexture.h"

AtlasTexture::AtlasTexture():Texture() {

}

AtlasTexture::AtlasTexture(unsigned int cellWidth, unsigned int cellHeight): Texture(){
    setCellSize(cellWidth,cellHeight);
}

AtlasTexture::AtlasTexture(std::string path, unsigned int cellWidth, unsigned int cellHeight):Texture(path) {
    load(path);
    setCellSize(cellWidth,cellHeight);
}

void AtlasTexture::setCellSize(unsigned int cellWidth, unsigned int cellHeight){
    this->cellHeight=cellHeight;
    this->cellWidth=cellWidth;
}


void AtlasTexture::getCoordinates(float (&uvs)[8], unsigned int row, unsigned int column) const{
    uvs[0]=(float)(column*cellWidth)/width;
    uvs[1]=(float)(row*cellHeight)/height;
    uvs[2]=uvs[0]+cellWidth;
    uvs[3]=uvs[1];
    uvs[4]=uvs[0];
    uvs[5]=uvs[1]+cellHeight;
    uvs[6]=uvs[0]+cellWidth;
    uvs[7]=uvs[1]+cellHeight;
}



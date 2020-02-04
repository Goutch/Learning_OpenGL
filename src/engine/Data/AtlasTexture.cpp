//
// Created by User on 2020-01-09.
//

#include <Core/Log.h>
#include "AtlasTexture.h"

AtlasTexture::AtlasTexture():Texture() {

}

AtlasTexture::AtlasTexture(unsigned int cellWidth, unsigned int cellHeight): Texture(){
    setCellSize(cellWidth,cellHeight);
}

AtlasTexture::AtlasTexture(std::string path, unsigned int cellWidth, unsigned int cellHeight, bool flip_on_load)
        : Texture(path, flip_on_load) {
    load(path, flip_on_load);
    setCellSize(cellWidth,cellHeight);
}

void AtlasTexture::setCellSize(unsigned int cellWidth, unsigned int cellHeight){
    this->cellHeight=cellHeight;
    this->cellWidth=cellWidth;
}


void AtlasTexture::getCoordinates(float (&uvs)[8], unsigned int column,unsigned int row) const{
    row = (height - cellHeight)/cellHeight - row;

    uvs[0]=(float)(column*cellWidth)/width;
    uvs[1]=(float)(row*cellHeight)/height;
    uvs[2]=(float)(column*cellWidth)/width;
    uvs[3]=(float)(row*cellHeight+cellHeight)/height;
    uvs[4]=(float)(column*cellWidth+cellWidth)/width;
    uvs[5]=(float)(row*cellHeight+cellHeight)/height;
    uvs[6]=(float)(column*cellWidth+cellWidth)/width;
    uvs[7]=(float)(row*cellHeight)/height;
}

void AtlasTexture::getCoordinates(float (&uvs)[8], unsigned int index) const {

    unsigned int num_col=width/cellWidth;
    getCoordinates(uvs,(index%num_col),(index-(index%num_col))/num_col);
    Log::message(std::to_string(index)+":("+std::to_string((index%num_col))+","+std::to_string((index-(index%num_col))/num_col)+")");
}



#pragma once

class Texture;

#include "VAO.h"
class Sprite : public VAO{
    Texture* texture;

public:
    Sprite();
    Sprite(Texture& texture);
    void setTexture(Texture& texture);
    void bind() override ;
};



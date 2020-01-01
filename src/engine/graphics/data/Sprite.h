#pragma once

class Texture;

#include "VAO.h"
class Sprite : public VAO{
    Texture* texture;

public:
    Sprite(Texture* texture);
    void bind();
};


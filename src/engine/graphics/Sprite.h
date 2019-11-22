#pragma once

class Texture;

#include "Drawable.h"
class Sprite :public Drawable{
    Texture* texture;
public:
    Sprite(Texture* texture);
    void bind();
};


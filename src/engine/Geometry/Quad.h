#pragma once

#include "VAO.h"

class Quad : public VAO{

public:
    enum PIVOT{
        CENTER,
        UP,
        LEFT,
        RIGHT,
        DOWN,
        DOWN_LEFT,
        DOWN_RIGHT,
        UP_LEFT,
        UP_RIGHT,
    };
    Quad(PIVOT pivot=CENTER);
};

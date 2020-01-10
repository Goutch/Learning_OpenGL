#pragma once

#include "VAO.h"

class Text : VAO {
public:
    Text();
    Text(char* text, unsigned int size);
    void setText(char* text, unsigned int size);
};


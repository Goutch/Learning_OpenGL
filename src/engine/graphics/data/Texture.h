//
// Created by User on 22-Nov.-2019.
//

#pragma once
#include <string>
class Texture {
unsigned int texture_id;
int width;
int height;
int bits_per_pixel;

public:
    Texture();
    Texture(const std::string& path);
    ~Texture();
    void load(const std::string& path);

    Texture(char* data,int width,int height);
    void bind(unsigned int slot=0) const;
    void unbind(unsigned int slot=0) const;
};
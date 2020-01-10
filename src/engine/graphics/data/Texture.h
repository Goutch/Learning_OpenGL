//
// Created by User on 22-Nov.-2019.
//

#pragma once

#include <string>

class Texture {
    unsigned int texture_id;
    int bits_per_pixel;
protected:
    int width;
    int height;


public:
    Texture();

    Texture(const std::string &path);

    ~Texture();

    void load(const std::string &path);

    Texture(unsigned char *data, int width, int height);
    void bind(unsigned int slot = 0) const;
    void setTexturePixelData(unsigned char *data, int width, int height, bool smoothed);
    void unbind(unsigned int slot = 0) const;
    unsigned int getWidth();
    unsigned int getHeight();
};
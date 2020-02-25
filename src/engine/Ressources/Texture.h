//
// Created by User on 22-Nov.-2019.
//

#pragma once

#include <string>

class Texture {
public:
    enum Type{
        RGBA,
        RGB,
        DEPTH,
    };
private:
    Type type=RGBA;
    unsigned int texture_id;
    int bits_per_pixel;
protected:
    int width;
    int height;
public:
    Texture();

    Texture(const std::string &path, bool flip_on_load = true);

    virtual ~Texture();

    void load(const std::string &path, bool flip_on_load = true);

    Texture(unsigned char *data, int width, int height);
    void bind(unsigned int slot = 0) const;
    void setTexturePixelData(unsigned char *data, int width, int height, bool smoothed=true, Type type=RGBA);
    void unbind(unsigned int slot = 0) const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const unsigned int getID() const;
    void save(std::string path) const;
};
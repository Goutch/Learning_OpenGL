#pragma once

#include "Texture.h"
#include "RBO.h"

class FBO {
private:
    Texture texture;
    RBO rbo;
    unsigned int fbo_id;
public:
    FBO();
    FBO(int width,int height);
    ~FBO();
    void bind() const ;
    void unbind() const;
    void setSize(int width,int height);
    const Texture& getTexture();
    unsigned int getID();
};


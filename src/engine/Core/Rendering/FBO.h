#pragma once

#include "Ressources/Texture.h"
#include "RBO.h"

#include "vector"
class Window;
class FBO {
public:
    enum Type{
        COLOR,
        DEPTH,
    };
private:
    unsigned int width,height;
    Texture texture;
    std::vector<RBO> rbos;
    Type type=Type::COLOR;


    unsigned int fbo_id;

public:
    void setSize(int width,int height);
    FBO(int width,int height,Type type);
    FBO(Type type);
    ~FBO();
    void bind() const ;
    void unbind() const;

    const Texture& getTexture() const;
    unsigned int getID() const;
    void save(std::string path) const;
};


#pragma once
class Window;

class RBO {
public:
    enum Type{
        COLOR,
        STENCIL,
        DEPTH,
        DEPTH_AND_STENCIL
    };
private:
    Type type=DEPTH_AND_STENCIL;
    unsigned int rbo_id;


public:
    RBO();
    ~RBO();
    void bind() const ;
    void unbind() const;
    void setSize(int width,int height,Type type);

    unsigned int getID();
};

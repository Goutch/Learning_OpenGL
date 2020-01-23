#pragma once

class RBO {
private:
    unsigned int rbo_id;
public:
    RBO();
    RBO(int width,int height);
    ~RBO();
    void bind() const ;
    void unbind() const;
    void setSize(int width,int height);
    unsigned int getID();
};

#pragma once
class VBO
{
private:
    unsigned int vbo_id;
    unsigned int position;
    unsigned int atribute_size;
    unsigned int is_static;

public:
    VBO(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length,bool is_static);
    VBO(unsigned int atribute_position, unsigned int atribute_size, int* data, unsigned int data_length,bool is_static);
    void set(float* data,unsigned int data_length);
    void set(int *data, unsigned int data_length);
    ~VBO();
    void bind() const;
    void unbind() const;

};


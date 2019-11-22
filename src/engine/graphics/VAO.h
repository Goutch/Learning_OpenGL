#pragma once

#include <map>
class VBO;

class VAO
{
private:
    bool has_index_buffer=false;
    unsigned int index_buffer_id;
	unsigned int vao_id;
	std::map<unsigned  int,VBO*> vbos;
public:
	VAO();
	~VAO();
	void indicies(unsigned int* indicies,unsigned int indicies_lenght);
	void put(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length);
	void bind();
	void unbind();
};


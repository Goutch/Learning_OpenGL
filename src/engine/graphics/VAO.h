#pragma once

#include <map>
#include "VBO.h"

class VAO
{
private:
	unsigned int vao_id;
	std::map<unsigned  int,VBO*> vbos;
public:
	VAO();
	~VAO();
	void put(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length);
	void bind();
	void unbind();
};


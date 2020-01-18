#pragma once

#include <map>
class VBO;

class VAO
{
private:
    bool has_index_buffer=false;
    unsigned int index_buffer_id;
	unsigned int vao_id;
	unsigned int vertexCount=0;
	std::map<unsigned  int,VBO*> vbos;
public:
	VAO();
	~VAO();
	void indicies(unsigned int* indicies,unsigned int indicies_lenght);
	void put(unsigned int atribute_position, unsigned int atribute_count_per_vertex, float* data, unsigned int data_count);

    virtual void bind() const;
	void unbind() const;
	unsigned int getVertexCount() const;
};


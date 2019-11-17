#pragma once
#include <string>
class ShaderProgram
{
public:
	void bind();
	void unbind();
	ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	~ShaderProgram();
private:
	unsigned int program_id;
	unsigned int compileShader(unsigned int type, const std::string& source);
	std::string getSource(const std::string& path);
};


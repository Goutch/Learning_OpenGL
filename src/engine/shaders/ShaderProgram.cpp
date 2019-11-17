#define GLEW_STATIC
#include "ShaderProgram.h"
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
ShaderProgram::ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
{

    program_id = glCreateProgram();
    std::cout << "Compiling shader..."<<vertexShader << std::endl;
    unsigned int vs = compileShader(GL_VERTEX_SHADER, getSource(vertexShader));
    std::cout << "Compiling shader..." <<fragmentShader<< std::endl;
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, getSource(fragmentShader));

    glAttachShader(program_id, vs);
    glAttachShader(program_id, fs);
    glLinkProgram(program_id);
    glValidateProgram(program_id);

    glDeleteShader(vs);
    glDeleteShader(fs);

}

void ShaderProgram::bind()
{
	glUseProgram(program_id);
}
void ShaderProgram::unBind()
{
	glUseProgram(0);
}
unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source)
{

    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id,1,&src,nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result==GL_FALSE)
    {
    	int length;
    	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    	char* message=(char*)alloca(length*sizeof(char));
    	glGetShaderInfoLog(id, length, &length, message);
    	std::cout << "FAILED: Compile" << (type==GL_VERTEX_SHADER?"vertex shader":"frag shader")<<std::endl;
    	std::cout << message << std::endl;
    }
    else
    {
    	std::cout << "Shader compilation complete!" << std::endl;
    }

    return id;
}
std::string ShaderProgram::getSource(const std::string& path)
{
	try
	{
		std::ifstream file;
		file.open(path);
		std::stringstream strStream;
		strStream << file.rdbuf(); 
		return strStream.str(); 
	}
	catch (std::ios_base::failure& e) {
        std::cerr << "FAILED:Read " << path<< std::endl;
		std::cerr << e.what() << std::endl;
	}
	return "";
}
ShaderProgram::~ShaderProgram()
{
	glDeleteShader(program_id);
}




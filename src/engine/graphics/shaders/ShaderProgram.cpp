#define GLEW_STATIC

#include "ShaderProgram.h"
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>


ShaderProgram::ShaderProgram(const std::string &vertexShader, const std::string &fragmentShader) {

    program_id = glCreateProgram();

    std::cout << "Compiling vertex shader:" << vertexShader << std::endl;
    std::string sourcevs = getSource(vertexShader);
    unsigned int vs = compileShader(GL_VERTEX_SHADER, sourcevs);

    std::cout << "Compiling fragment shader:" << fragmentShader << std::endl;
    std::string sourcefs = getSource(fragmentShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, sourcefs);

    glAttachShader(program_id, vs);
    glAttachShader(program_id, fs);
    glLinkProgram(program_id);
    glValidateProgram(program_id);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

ShaderProgram::~ShaderProgram() {
    glDeleteShader(program_id);
}
void ShaderProgram::bind() {
    glUseProgram(program_id);
}

void ShaderProgram::unbind() {
    glUseProgram(0);
}

unsigned int ShaderProgram::compileShader(unsigned int type, const std::string &source) {
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << "FAILED:" << std::endl;
        std::cerr << message << std::endl;
    }
    return id;
}

std::string ShaderProgram::getSource(const std::string &path) {
    try {
        std::ifstream file;
        file.open(path);
        if(file.is_open())
        {
            std::stringstream strStream;
            strStream << file.rdbuf();
            std::string str = strStream.str();
            file.close();
            return str;
        } else{
            std::cerr << "FAILED:Unable to find file:" <<path << std::endl;
        }

    }
    catch (std::ios_base::failure &e) {
        std::cerr << "FAILED:Read " << path << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return "";
}





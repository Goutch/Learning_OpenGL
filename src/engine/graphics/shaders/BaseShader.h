#pragma once
class Entity;
#include "ShaderProgram.h"
class BaseShader :public ShaderProgram{

    int transform_location;
    int texture_location;
    int second_tex_location;
    void getUniformsLocations();
public:
    BaseShader();
    void loadEntityUniforms(Entity& e);
};

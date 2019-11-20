#pragma once
class Entity;
#include "ShaderProgram.h"
class BaseShader :public ShaderProgram{

    unsigned int transform_location;
    void getUniformsLocations();
public:
    BaseShader();
    void loadEntityUniforms(Entity& e);
};

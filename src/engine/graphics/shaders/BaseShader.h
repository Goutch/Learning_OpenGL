#pragma once
class Entity;
#include "ShaderProgram.h"
class BaseShader :public ShaderProgram{

    int transform_location;
    int texture_location;
    int has_texture_location;
    void getUniformsLocations();
public:
    BaseShader();
    void loadEntityUniforms(Entity& e);
};

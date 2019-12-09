#pragma once
class Entity;
#include "ShaderProgram.h"
class BaseShader :public ShaderProgram{

    int transform_location;
    int texture_0_location;
    int has_texture_location;
    int projection_mat_location;
    void getUniformsLocations();
public:
    BaseShader();
    void loadProjectionMatrix(glm::mat4& projection_mat);
    void loadEntityUniforms(Entity& e);
};

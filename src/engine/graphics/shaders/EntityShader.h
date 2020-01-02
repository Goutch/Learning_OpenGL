#pragma once
class Entity;
#include "ShaderProgram.h"
class EntityShader : public ShaderProgram{

    int transform_location;
    int texture_0_location;
    int has_texture_location;
    int projection_mat_location;
    int view_mat_location;
    void getUniformsLocations();
public:
    EntityShader();
    void loadProjectionMatrix(const mat4& projection_mat);
    void loadViewMatrix(const mat4& view_mat);
    void loadEntityUniforms(Entity& e);
};

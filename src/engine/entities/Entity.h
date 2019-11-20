#pragma once



#include "core/Window.h"
#include "core/Renderer.h"
class Entity{
public:
    virtual void render(Renderer& renderer)=0;
    virtual void update(float delta,Window& window)=0;
    virtual ShaderProgram& getShader()=0;
    virtual Transform& getTranform()=0;
    virtual Mesh& getMesh()=0;
};
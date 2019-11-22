#pragma once




#include "Transform.h"
class Renderer;
class BaseShader;
class Transform;
class Mesh;
class Window;
class Entity{
public:
    Transform transform;
    virtual void render(Renderer& renderer)=0;
    virtual void update(float delta,Window& window)=0;
    virtual BaseShader& getShader()=0;
    virtual Mesh& getMesh()=0;
};
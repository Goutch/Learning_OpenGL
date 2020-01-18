#pragma once




#include "Transform.h"
class Renderer;
class Transform;
class VAO;
class Window;
class Scene;
class Entity{
public:
    Transform transform;
    Entity(vec3 position,vec3 rotation,vec3 scale);
    Entity();
    virtual void render(Scene& scene);
    virtual void update(float delta,Scene& scene);
};
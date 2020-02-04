#pragma once




#include "Transform.h"
class Transform;
class VAO;
class Window;
class Scene;

class Entity{
public:
    Transform transform;
    Entity(vec3 position=vec3(0),vec3 rotation=vec3(0),vec3 scale=vec3(1));
    virtual void init(Scene& scene);
    virtual void draw(const Scene& scene) const;
    virtual void update(float delta,Scene& scene);
    virtual void destroy(Scene& scene);
};
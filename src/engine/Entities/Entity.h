#pragma once


class Scene;

#include "Transform.h"
class Scene;

#include <string>
#include <set>
class Entity{
    std::string name;
    std::set<Entity*> children;
public:
    Transform transform;
    Entity(vec3 position, vec3 rotation=vec3(0), vec3 scale=vec3(1));
    Entity();
    void addChild(Entity* child);
    void removeChild(Entity* child);
    void removeChild(std::string name);
    void removeChild(unsigned int index);
    void setParent(Entity* parent);
    std::set<Entity*> getChildren();
    virtual void init(Scene &scene);
    virtual void draw(const Scene &scene) const;
    virtual void update(float delta, Scene &scene);
    virtual void onDestroy(Scene &scene);
    void setName(const std::string &name);
    const std::string &getName() const;


};
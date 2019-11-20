#pragma once

class Entity;
#include <list>
class Renderer
{
    std::list<Entity*> entities;
public:
    Renderer();
    ~Renderer();
	virtual void addToRenderQueue(Entity* entity);
	virtual void render();
};
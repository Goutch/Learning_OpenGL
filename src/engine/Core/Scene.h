#pragma once

class Window;
class Renderer;
class Entity;
class Transform;
class MeshRenderer;

#include "Entities/Transform.h"
#include "vector"
class Scene
{
protected:
    Window* window;
    Renderer* renderer;
    std::vector<Entity*> entities;
public:
    Transform camera;
    ~Scene();
	Scene();
	virtual void init(Window &window,Renderer &renderer);
	virtual void update(float delta);
	virtual void render();
    unsigned int addEntity(Entity& entity);
    unsigned int addEntity(Entity* entity);
	Window& getWindow();
	Renderer& getRenderer();

};

#pragma once

class Window;
class Renderer;
class Entity;
class Transform;
class MeshRenderer;
class PointLight;
#include "Entities/Transform.h"
#include "Data/Color.h"
#include "vector"
class Scene
{
protected:
    Window* window;
    Renderer* renderer;
    std::vector<Entity*> entities;
    std::vector<PointLight*> point_lights;
    Color ambient_light=Color(0.5,0.5,0.5);
public:
    Transform camera;
    ~Scene();
	Scene();
	virtual void init(Window &window,Renderer &renderer);
	virtual void update(float delta);
	virtual void render();
    void addEntity(Entity& entity);
    void addEntity(Entity* entity);
    void addLight(PointLight* light);
    const std::vector<PointLight*>& getPointLights() const;
    const Color& getAmbientLight() const;
    const Transform& getCamera() const;
	Window& getWindow();
	Renderer& getRenderer();

};

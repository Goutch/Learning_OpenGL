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
class DirectionalLight;
class Scene
{
protected:
    Window* window;
    Renderer* renderer;
    std::vector<Entity*> entities;
    std::vector<PointLight*> point_lights;
    std::vector<DirectionalLight*> directional_lights;
    Color ambient_light=Color(0.1,0.1,0.1);
public:
    Transform camera;
    ~Scene();
	Scene();
	virtual void init(Window &window,Renderer &renderer);
	virtual void update(float delta);
	virtual void render() const;
    void addEntity(Entity& entity);
    void addEntity(Entity* entity);
    void addLight(PointLight* light);
    void addLight(DirectionalLight* light);
    const std::vector<PointLight*>& getPointLights() const;
    const std::vector<DirectionalLight*>& getDirectionalLights() const;
    const Color& getAmbientLight() const;
    const Transform& getCamera() const;
	Window& getWindow()const;
	Renderer& getRenderer()const ;

};

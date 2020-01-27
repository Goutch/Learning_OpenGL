#pragma once

class Window;
class Renderer;
class Entity;
class Transform;
class MeshRenderer;
class PointLight;
class DirectionalLight;
class Camera;
class Viewport;
#include "Data/FBO.h"
#include "Entities/Transform.h"
#include "Data/Color.h"
#include "vector"

class Scene
{
protected:
    FBO frame_buffer=FBO(FBO::COLOR);
    Viewport* viewport;
    Window* window;
    Renderer* renderer;
    std::vector<Entity*> entities;
    std::vector<PointLight*> point_lights;
    std::vector<DirectionalLight*> directional_lights;
    Color ambient_light=Color(0.1f,0.1f,0.1f);
public:
    Camera* camera;
    ~Scene();
	Scene();
	virtual void init(Viewport &viewport,Renderer &renderer,Window& window);
	virtual void update(float delta);
	virtual void render() const;
    void addEntity(Entity& entity);
    void addEntity(Entity* entity);
    void addLight(PointLight* light);
    void addLight(DirectionalLight* light);
    const std::vector<PointLight*>& getPointLights() const;
    const std::vector<DirectionalLight*>& getDirectionalLights() const;
    const Color& getAmbientLight() const;
    const Camera& getCamera() const;
	const Viewport& getViewport()const;
    Window& getWindow() const;
	Renderer& getRenderer()const ;
    const FBO& getFBO() const;
};

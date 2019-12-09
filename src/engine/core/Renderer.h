#pragma once

class Entity;
class Window;
#include "glm/glm.hpp"
#include <list>

class Renderer
{
private:
    glm::mat4 projection_matrix;
    std::list<Entity*> entities;
public:
    enum RenderMode{
        ORTHOGRAPHIC,
        PERSPECTIVE
    };
    Renderer(Window& window,RenderMode mode);
    ~Renderer();
	virtual void addToRenderQueue(Entity* entity);
	virtual void render();
	void setRenderMode(Window& window,RenderMode renderMode);
};
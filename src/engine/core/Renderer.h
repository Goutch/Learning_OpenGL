#pragma once

class MeshRenderer;
class Window;
class Camera;

#include "glm/mat4x4.hpp"

#include <list>
using namespace glm;
class Renderer
{
private:
    mat4 projection_matrix;
    std::list<MeshRenderer*> entities;
    Camera* cam;
public:
    enum RenderMode{
        ORTHOGRAPHIC,
        PERSPECTIVE
    };
    Renderer(Window& window,RenderMode mode);
    ~Renderer();
	virtual void addToRenderQueue( MeshRenderer& entity);
	virtual void render();
	virtual void setCamera(Camera& camera);
	void setRenderMode(Window& window,RenderMode renderMode);
};
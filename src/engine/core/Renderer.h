#pragma once

class MeshRenderer;
class Window;
class Transform;

#include "glm/mat4x4.hpp"
class Shader;
#include <list>
using namespace glm;
class Renderer
{
private:
    float aspect_ratio;
    float fov=90;
    mat4 projection_matrix;
    std::list<MeshRenderer*> entities;
    const Transform* cam;
public:
    enum RenderMode{
        ORTHOGRAPHIC,
        PERSPECTIVE
    };
    Renderer(Window& window,RenderMode mode);
    ~Renderer();
	virtual void addToRenderQueue( MeshRenderer& entity);
	virtual void render();
	virtual void setCamera(Transform& camera);
	void setRenderMode(Window& window,RenderMode renderMode);
	float getFOV();
	float getAspectRatio();
};
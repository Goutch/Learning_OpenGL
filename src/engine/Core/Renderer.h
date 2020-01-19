#pragma once

class MeshRenderer;
class Window;
class Transform;

#include "glm/mat4x4.hpp"
class Material;
class VAO;
#include <unordered_map>
#include "list"
using namespace glm;
class Renderer
{
private:
    float aspect_ratio;
    float fov=90;
    mat4 projection_matrix;
    std::unordered_map<Material*,std::unordered_map<VAO*,std::list<Transform*>>> material_batch;
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
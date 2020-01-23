#pragma once

class MeshRenderer;
class Window;
class Transform;

#include "glm/mat4x4.hpp"
#include "Data/Texture.h"
class Material;
class VAO;
class Scene;
class Shader;


#include "Geometry/VAO.h"
#include "Events/WindowSizeListener.h"
#include <unordered_map>
#include "list"
#include "Geometry/Geometry.h"
#include "Shaders/Shader.h"
#include "Data/FBO.h"
#include "Data/RBO.h"
using namespace glm;
class Renderer:WindowSizeListener
{
public:
    enum RenderMode{
        ORTHOGRAPHIC_PIXEL=0,
        ORTHOGRAPHIC_UNITS=1,
        PERSPECTIVE=2
    };
private:
    FBO frame_buffer;
    VAO quad;
    Shader screenShader=Shader("../src/engine/Shaders/shadersSources/ScreenVertex.glsl",
                               "../src/engine/Shaders/shadersSources/ScreenFragment.glsl");
    RenderMode currentRenderMode=PERSPECTIVE;
    float aspect_ratio;
    float fov=90;
    mat4 projection_matrix;
    std::unordered_map<Material*,std::unordered_map<VAO*,std::list<Transform*>>> material_batch;
    const Transform* cam;
public:

    Renderer(Window& window,RenderMode mode);
    Renderer(Window& window);
    ~Renderer();
	virtual void addToRenderQueue(Material& material,VAO& vao,Transform& transform);
	virtual void render(const Scene& scene);
	virtual void setCamera(Transform& camera);
	void setRenderMode(int width, int height, RenderMode renderMode);
	float getFOV();
    float getAspectRatio();
    void onWindowSizeChange( int width, int height) override;
    const Texture& getFrameBufferTexture();
    void screenshot() const;
};
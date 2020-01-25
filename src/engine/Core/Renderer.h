#pragma once



#include "glm/mat4x4.hpp"
#include "Data/Texture.h"
#include "Geometry/VAO.h"
#include "Events/WindowSizeListener.h"
#include <unordered_map>
#include "list"
#include "Geometry/Geometry.h"
#include "Shaders/Shader.h"
#include "Data/FBO.h"
#include "Data/RBO.h"

class MeshRenderer;
class Window;
class Transform;
class Material;
class VAO;
class Scene;
class Shader;

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
    FBO* frame_buffer;
    Window* window;
    VAO quad;
    Shader shadowMapShader=Shader("../src/engine/Shaders/shadersSources/ShadowMapVertex.glsl",
                               "../src/engine/Shaders/shadersSources/ShadowMapFragment.glsl");
    int shadowMapShader_light_space_matrix_location;
    int shadowMapShader_transform_mat_location;
    Shader screenShader=Shader("../src/engine/Shaders/shadersSources/ScreenVertex.glsl",
                               "../src/engine/Shaders/shadersSources/ScreenFragment.glsl");
    RenderMode currentRenderMode=PERSPECTIVE;
    double aspect_ratio;
    float fov=90;
    mat4 projection_matrix;
    mutable std::unordered_map<const Material*,std::unordered_map<const VAO*,std::list<const Transform*>>> material_batch;

public:

    Renderer(Window& window,RenderMode mode);
    Renderer(Window& window);
    ~Renderer();
	virtual void addToRenderQueue(const Material& material,const VAO& vao, const Transform& transform);
	virtual void render(const Scene& scene);
	virtual void renderBufferInQuad(FBO& buffer);
    virtual void renderSceneToBuffer(FBO& buffer, const Scene& scene, const Transform& camera, const glm::mat4& projection);
    virtual void renderShadowMapToBuffer(FBO& buffer, const Scene& scene,const glm::mat4& depth_mat);
	void setRenderMode(int width, int height, RenderMode renderMode);
	float getFOV() const;
    double getAspectRatio()const;
    void onWindowSizeChange( int width, int height) override;
    const Texture& getFrameBufferTexture()const;
    void screenshot() const;
};
#pragma once
#include "glm/mat4x4.hpp"


class MeshRenderer;

class Window;

class Transform;

class Material;

class VAO;

class Scene;

class Shader;

class Camera;
class Texture;
class FBO;
using namespace glm;

class Viewport;
class Renderer {
public:
    void clear();
    void clearDepth();
    void clearColor();
    virtual void addToRenderQueue(const VAO &vao,const Material &material,const Transform& transform)=0;
    virtual void draw(const VAO& vao, const Shader& shader, const Texture& texture);
    virtual void render(const FBO &buffer, const Scene &scene, const glm::mat4 &space_mat=mat4(1.0f))=0;
    virtual void renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat)=0;
};

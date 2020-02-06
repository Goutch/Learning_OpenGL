#pragma once

class Window;
class Renderer;
class SpacialEntity;
class Transform;
class MeshRenderer;

class Canvas;

#include <GLFW/glfw3.h>
#include "Data/FBO.h"
#include "Entities/Canvas/CanvasEntity.h"
#include "Data/Color.h"
#include "vector"

class Scene
{
protected:
    const Canvas* canvas;
    Window* window;
    Renderer* renderer;
    std::vector<CanvasEntity*> canvasEntities;

public:
	Scene();
	virtual void init(const Canvas &canvas, Renderer &renderer, Window& window);
	virtual void update(float delta);
	virtual void draw() const;
	virtual void render() const;
	virtual void destroy();
    void addEntity(CanvasEntity* entity);
	const Canvas& getCanvas() const;
    Window& getWindow() const;
	Renderer& getRenderer()const ;
};

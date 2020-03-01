#pragma once

class Input;
class Renderer;
class SpacialEntity;
class Transform;
class MeshRenderer;

class Canvas;

#include <GLFW/glfw3.h>
#include "Core/Rendering/FBO.h"
#include "Entities/Canvas/CanvasEntity.h"
#include "Ressources/Color.h"
#include "vector"

class Scene
{
protected:
    const Canvas* canvas;
    Input* input;
    Renderer* renderer;
    std::vector<CanvasEntity*> canvasEntities;

public:
	Scene();

	virtual void init(const Canvas &canvas, Renderer &renderer, Input &input);
	virtual void update(float delta);
	virtual void draw() const;
	virtual void render() const;
    ~Scene();
    void addEntity(CanvasEntity* entity);
	const Canvas& getCanvas() const;
    Input& getInput() const;
	Renderer& getRenderer()const ;
};

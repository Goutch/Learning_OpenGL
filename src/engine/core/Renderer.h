#pragma once

#include "entities/Transform.h"
#include "graphics/shaders/ShaderProgram.h"
#include "graphics/Mesh.h"
#include "entities/Entity.h"
class Renderer
{

public:
    virtual ~Renderer(){};
	virtual void addToRenderQueue(Entity& entity)=0;
	virtual void render()=0;
};
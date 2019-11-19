#pragma once

#include <engine/graphics/Mesh.h>

class Renderer
{

public:
    virtual ~Renderer(){};
	virtual void addToRenderQueue(Mesh* mesh)=0;
	virtual void render()=0;
};
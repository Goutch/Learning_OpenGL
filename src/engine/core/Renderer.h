#pragma once

#include <engine/graphics/VAO.h>

class Renderer
{
public:

	virtual void addToRenderQueue(VAO* objectVAO)=0;
	virtual void render()=0;
};
#pragma once

#include <engine/core/Window.h>
#include "Renderer.h"

class Game
{

private:

public:

	Game(){
	};
	virtual void init()=0;
	virtual void update(Window& window)=0;
	virtual void render(Renderer& renderer)=0;
};

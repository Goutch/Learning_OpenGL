#pragma once
#include "../graphics/Renderer.h"

class Game
{
public:
	Game(Renderer& renderer);
	void init();
	void update();
	void render();
};

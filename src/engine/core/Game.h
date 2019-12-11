#pragma once

class Window;
class Renderer;

class Game
{

private:

public:

	Game(){
	};
	virtual void init(Window &window,Renderer &renderer)=0;
	virtual void update()=0;
	virtual void render()=0;
};

#pragma once
class Renderer
{
public:
	virtual void addToRenderQueue() = 0;
	virtual void render() = 0;
};
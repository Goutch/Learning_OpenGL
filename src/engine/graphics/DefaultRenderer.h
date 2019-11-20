
#pragma once

#include "core/Renderer.h"

#include <list>
#include <map>
#include "entities/Entity.h"
class DefaultRenderer:public Renderer {
protected:
    std::list<Entity> entities;
public:
    DefaultRenderer();
    ~DefaultRenderer() override;

    void render() override;

    void addToRenderQueue(Entity& entity ) override;
};



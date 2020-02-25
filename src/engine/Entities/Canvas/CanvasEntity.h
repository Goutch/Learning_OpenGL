#pragma once

class Scene;
#include "CanvasTransform.h"
#include "Entities/Entity.h"
class CanvasEntity:Entity {
public:
    CanvasTransform transform;
    CanvasEntity();
    CanvasEntity(vec2 position,float rotation=0,vec2 scale=vec2(1));
    virtual void onDestroy(Scene &scene);
    virtual void draw(const Scene &scene) const;
    virtual void update(float delta, Scene &scene);
    virtual void init(Scene &scene);
};


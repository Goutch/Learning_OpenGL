#pragma once

class Scene;
#include "CanvasTransform.h"

class CanvasEntity {
public:
    CanvasTransform transform;
    CanvasEntity();
    CanvasEntity(vec2 position,float rotation=0,vec2 scale=vec2(0));
    virtual void onDestroy(Scene &scene);
    virtual void draw(const Scene &scene) const;
    virtual void update(float delta, Scene &scene);
    virtual void init(Scene &scene);
};

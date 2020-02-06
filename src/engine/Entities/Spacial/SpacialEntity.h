#pragma once


class SpacialScene;
#include "Entities/Spacial/Transform.h"
class Scene;

class SpacialEntity{
public:
    Transform transform;
    SpacialEntity(vec3 position=vec3(0), vec3 rotation=vec3(0), vec3 scale=vec3(1));
    virtual void init(SpacialScene &scene);
    virtual void draw(const SpacialScene &scene) const;
    virtual void update(float delta, SpacialScene &scene);
    virtual void onDestroy(SpacialScene &scene);
};
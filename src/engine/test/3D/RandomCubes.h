#pragma once

#include <vector>
#include <graphics/data/Sprite.h>
#include <graphics/shaders/EntityShader.h>
#include <graphics/data/Texture.h>
#include <graphics/data/Mesh.h>
#include "core/Scene.h"
class RandomCubes : public Scene {
private:

    EntityShader* shader;
    Entity* camera;
    Mesh* mesh;
    Texture stone;

public:
    RandomCubes();

    ~RandomCubes();

    void init(Window &window,Renderer &renderer) override;

    void update(float delta) override ;
};



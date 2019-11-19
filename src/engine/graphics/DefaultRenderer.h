
#pragma once

#include "../core/Renderer.h"
#include "shaders/ShaderProgram.h"
#include "Mesh.h"
#include <list>
class DefaultRenderer:public Renderer {
protected:
    ShaderProgram* shader;
    std::list<Mesh*> objects;
public:
    DefaultRenderer();
    ~DefaultRenderer() override;

    void render() override;
    void addToRenderQueue(Mesh* mesh) override;
};



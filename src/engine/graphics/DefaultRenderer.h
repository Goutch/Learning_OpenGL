
#pragma once

#include "../core/Renderer.h"
#include "shaders/ShaderProgram.h"
#include <list>
class DefaultRenderer:public Renderer {
protected:
    ShaderProgram* shader;
    std::list<VAO*> objects;
public:
    DefaultRenderer();
    ~DefaultRenderer() override;

    void render() override;
    void addToRenderQueue(VAO* objectVAO) override;
};




#pragma once

#include "../core/Renderer.h"
#include <list>
class DefaultRenderer:public Renderer {
protected:
    std::list<VAO*> objects;
public:
    DefaultRenderer();
    ~DefaultRenderer();

    void render() override;
    void addToRenderQueue(VAO* objectVAO) override;
};



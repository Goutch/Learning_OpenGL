#pragma once

#include <Core/Scene.h>

class Editor: public Scene{
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;


    void update(float delta) override;

    void render() const override;
};

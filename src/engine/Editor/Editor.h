#pragma once

#include <Core/Scene.h>

class Editor: public Scene{
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

    void render() const override;
};

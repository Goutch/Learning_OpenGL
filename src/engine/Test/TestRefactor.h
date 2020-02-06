#pragma once

#include <Core/SpacialScene.h>

class TestRefactor : public SpacialScene{
    VAO vao;
public:
    void init(Canvas &canvas, Renderer &renderer, Window &window) override;
};

#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Test/SpacialSceneTest.h"

class Editor: public Scene{
    Scene* current_scene;
    Canvas* current_scene_canvas;
    mutable Color color;


public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;
    Editor(Scene* scene);
    ~Editor();
    void update(float delta) override;
    void setScene(Scene* scene);
    void draw() const override ;
};



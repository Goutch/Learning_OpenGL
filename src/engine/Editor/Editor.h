#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Test/SpacialSceneTest.h"
class Editor: public Scene{
    Scene* current_scene;
    Canvas* current_scene_canvas;
    CanvasTransform current_scene_canvas_transform;
    CanvasMaterial current_scene_canvas_material;

public:
    void init(const Canvas &canvas, Renderer &renderer, Window &window) override;
    Editor(Scene& scene);
    ~Editor();
    void update(float delta) override;

    void draw() const override ;

    void render() const override;
};



#pragma once

#include <Core/Scene.h>
#include <Core/Viewport.h>
#include "Test/FullSceneTest.h"
class Editor: public Scene{
    Scene* current_scene;
    Viewport* current_scene_viewport;
    Material screen_mat;
    VAO scene_screen;
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;
    Editor(Scene& scene);
    ~Editor();
    void update(float delta) override;

    void render() const override;
    void prepareRender() const override ;

};



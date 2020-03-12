#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Scenes/Demo3D/SpacialSceneDemo.h"
#include "set"
#include "vector"
#include <list>
#include "PropertyWindow.h"
#include "SceneTreeWindow.h"
#include "CameraWindow.h"
class Editor: public Scene{

    Scene* current_scene;
    Canvas* current_scene_canvas;
    PropertyWindow properties;
    SceneTreeWindow scene_tree;
    std::map<Camera*,CameraWindow*> cameras;
    mutable Color color;
    mutable std::set<Entity*> selected_entities;

    Shader shader = Shader("../res/shaders/LightVertex.glsl",
                                "../res/shaders/LightFragment.glsl");
    LightMaterial* material;
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    Editor(Scene* scene);
    Editor();
    ~Editor();
    void update(float delta) override;

};



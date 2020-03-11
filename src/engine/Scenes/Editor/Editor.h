#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Scenes/Demo3D/SpacialSceneDemo.h"
#include "set"
#include "vector"
#include <list>
#include "PropertyWindow.h"
#include "SceneTreeWindow.h"
class Editor: public Scene{
    mutable std::vector<Camera*> cameras;
    mutable std::vector<Canvas*> cameras_canvas;
    Scene* current_scene;
    PropertyWindow properties;
    SceneTreeWindow scene_tree;

    mutable Color color;
    mutable std::set<Entity*> selected_entities;

    Shader shader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");
    LightMaterial* material;
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    Editor(Scene* scene);
    Editor();
    ~Editor();
    void update(float delta) override;

};



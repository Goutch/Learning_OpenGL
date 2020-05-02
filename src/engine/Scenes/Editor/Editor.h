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
#include "EntityCreationWindow.h"

class Editor: public Scene{

    Scene* current_scene;
    Canvas* current_scene_canvas;
    PropertyWindow properties;
    SceneTreeWindow scene_tree;
    EntityCreationWindow* entity_creator;
    std::map<Camera*,CameraWindow*> cameras;
    mutable Color color;
    mutable std::set<Entity*> selected_entities;

    ImVec2 p1;
    ImVec2 p2;
    ImVec2 p3;
    ImVec2 p4;
public:
    void init(Canvas &canvas, Renderer &renderer, Input &input) override;

    Editor(Scene* scene);
    Editor();
    ~Editor();
    void update(float delta) override;

};



#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Scenes/Demo3D/SpacialSceneDemo.h"
#include "set"

class Editor: public Scene{

    SpacialScene* current_scene;
    Canvas* current_scene_canvas;
    mutable Color color;
    mutable std::set<SpacialEntity*> selectedEntities;
    mutable float posX = 0;
    mutable float rotX = 0;
    mutable float sizeX = 1;
    mutable float posY = 0;
    mutable float rotY = 0;
    mutable float sizeY = 1;
    mutable float posZ = 0;
    mutable float rotZ = 0;
    mutable float sizeZ = 1;
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;
    Editor(SpacialScene* scene);
    Editor();
    ~Editor();
    void update(float delta) override;
    void setScene(SpacialScene* scene);
    void draw() const override ;
};



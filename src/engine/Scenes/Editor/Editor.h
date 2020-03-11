#pragma once

#include <Core/Scene.h>
#include <Core/Canvas.h>
#include "Scenes/Demo3D/SpacialSceneDemo.h"
#include "set"
#include "vector"
#include <list>
class Editor: public Scene{

    mutable std::vector<Camera*> cameras;
    mutable std::vector<Canvas*> cameras_canvas;
    Scene* current_scene;
    mutable int lightCount=0;
    mutable Color color;
    mutable std::set<Entity*> selectedEntities;
    mutable float posX = 0;
    mutable float rotX = 0;
    mutable float sizeX = 1;
    mutable float posY = 0;
    mutable float rotY = 0;
    mutable float sizeY = 1;
    mutable float posZ = 0;
    mutable float rotZ = 0;
    mutable float sizeZ = 1;
    mutable bool activeRotation = false;
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/LightVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LightFragment.glsl");
    LightMaterial* material;
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    Editor(Scene* scene);
    Editor();
    ~Editor();
    void update(float delta) override;
    void createHierachy() const;
    void draw() const override ;
};



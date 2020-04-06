#pragma once

#include <imgui.h>
#include <Core/Scene.h>
#include <Ressources/Shaders/Material/LightMaterial.h>
#include <Ressources/Shaders/Shader.h>
#include "CameraWindow.h"

class EntityCreationWindow {
    Shader shader = Shader("../res/shaders/LightVertex.glsl",
                           "../res/shaders/LightFragment.glsl");
    LightMaterial* material;

public:
    EntityCreationWindow(Scene* scene);
    void update(Scene *scene, Entity *parent,std::set<Entity*>& selected_entities, ImGuiID dockspace_id,
                std::map<Camera *, CameraWindow *>& cameras);
    ~EntityCreationWindow();
};


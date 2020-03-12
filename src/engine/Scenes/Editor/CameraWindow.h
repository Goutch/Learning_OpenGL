#pragma once

#include <Core/Rendering/FBO.h>
#include <Entities/Camera.h>
#include <imgui.h>
#include <Core/Rendering/Renderer.h>
#include <Core/Input.h>

class CameraWindow {
    FBO fbo=FBO(1,1,FBO::COLOR);
    void handleMovement(Input* input,Camera* camera);
    bool has_clicked=false;
    vec2 last_cusor_pos;
    vec3 dir;
public:
    void update(Scene* scene,Renderer* renderer,Input* input,Camera* camera,ImGuiID dockspace_id);

};

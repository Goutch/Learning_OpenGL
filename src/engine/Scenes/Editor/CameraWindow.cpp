//
// Created by User on 12-Mar.-2020.
//

#include "CameraWindow.h"
#include <Core/Scene.h>
void CameraWindow::update(Scene* scene,Renderer* renderer,Input* input,Camera* camera,ImGuiID dockspace_id) {

    if(input->getMouseButtonReleased(0))
    {
        input->setCursor(Input::ARROW);
        has_clicked=false;
    }
    //todo fix bugs with camera projection not updating
    ImGui::SetNextWindowDockID(dockspace_id, ImGuiCond_FirstUseEver);
    ImGui::Begin(camera->getName().c_str());
    {
        ImVec2 vMin = ImGui::GetWindowContentRegionMin();
        ImVec2 vMax = ImGui::GetWindowContentRegionMax();
        Camera::ProjectionMode mode = scene->getCamera().getProjectionMode();
        ImGui::BeginChild("Projection");
        if (ImGui::Button(mode == Camera::ProjectionMode::PERSPECTIVE ? "Perspective" : "Orthographic")) {
            if (mode == Camera::ORTHOGRAPHIC)
                scene->getCamera().setProjectionPerspective(vMax.x, vMax.y);
            else
                scene->getCamera().setProjectionOrthographic(10, 10);
        }
        ImGui::EndChild();

        if (vMax.x != fbo.getTexture().getWidth() ||
            vMax.y != fbo.getTexture().getHeight())
        {
            fbo.setSize(vMax.x, vMax.y);
            if (mode == Camera::PERSPECTIVE)
                scene->getCamera().setProjectionPerspective(vMax.x, vMax.y);
            else
                scene->getCamera().setProjectionOrthographic(10, 10);
        }

        vMin.x += ImGui::GetWindowPos().x;
        vMin.y += ImGui::GetWindowPos().y;
        vMax.x += ImGui::GetWindowPos().x;
        vMax.y += ImGui::GetWindowPos().y;
        ImGui::GetWindowDrawList()->AddImage(
                (void *) fbo.getTexture().getID(),
                vMin,
                vMax,
                ImVec2(0, 1),
                ImVec2(1, 0));
        if(ImGui::IsItemClicked())
        {
            input->setCursor(Input::HAND);
            has_clicked=true;
            double x,y;
            input->getMousePosition(x,y);
            last_cusor_pos.x=x;
            last_cusor_pos.y=y;
        }
        if(has_clicked)
        {
            handleMovement(input,camera);
        }
    }
    ImGui::End();
    scene->draw();
    scene->setCamera(*camera);
    renderer->render(fbo, camera->getProjectionMatrix(),
                     camera->getViewMatrix());
}

void CameraWindow::handleMovement(Input *input, Camera *camera) {
    double x,y;
    input->getMousePosition(x,y);
    float fov=camera->getFOV();
    float w=fbo.getTexture().getWidth(),h=fbo.getTexture().getHeight();
    double aspect_ratio=h/w;
    vec2 change;
    change.x=((x-last_cusor_pos.x)/w)*fov;
    change.y=((y-last_cusor_pos.y)/h)*(fov*aspect_ratio);
    vec3 rot=camera->transform.eulerRotation();
    camera->transform.rotate(quat(vec3(glm::radians(change.y*cos(rot.y)),glm::radians(change.x),glm::radians(change.y*sin(rot.y)))));
    last_cusor_pos.x=x;
    last_cusor_pos.y=y;

}

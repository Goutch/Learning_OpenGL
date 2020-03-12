//
// Created by User on 12-Mar.-2020.
//

#include "CameraWindow.h"
#include <Core/Scene.h>
void CameraWindow::update(Scene* scene,Renderer* renderer,Input* input,Camera* camera,ImGuiID dockspace_id) {

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
                scene->getCamera().setProjectionOrtho(10, 10);
        }
        ImGui::EndChild();

        if (vMax.x != fbo.getTexture().getWidth() ||
            vMax.y != fbo.getTexture().getHeight())
        {
            fbo.setSize(vMax.x, vMax.y);
            if (mode == Camera::PERSPECTIVE)
                scene->getCamera().setProjectionPerspective(vMax.x, vMax.y);
            else
                scene->getCamera().setProjectionOrtho(10, 10);
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
    }
    ImGui::End();
    scene->draw();
    scene->setCamera(*camera);
    renderer->render(fbo, camera->getProjectionMatrix(),
                     camera->getViewMatrix());
}

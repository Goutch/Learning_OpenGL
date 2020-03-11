//
// Created by User on 11-Mar.-2020.
//

#include "PropertyWindow.h"

void PropertyWindow::update(ImGuiID dockspace_id,std::set<Entity*>& selected_entities) {
    ImGui::SetNextWindowDockID(dockspace_id, ImGuiCond_FirstUseEver);

    ImGui::Begin("Properties");
    {
        if (!selected_entities.empty()) {
            vec3 position_change=vec3(0);
            vec3 rotation_change=vec3(0);
            vec3 scale_change=vec3(0);
            ImGui::SetNextWindowDockID(dockspace_id, ImGuiCond_FirstUseEver);
            ImGui::BeginChild("Transform");
            {
                Transform& transform=(*selected_entities.begin())->transform;
                position=transform.position();
                rotation=transform.eulerRotation();
                scale=transform.scale();
                ImGui::DragFloat3("position",&position.x,0.1f);
                ImGui::DragFloat3("rotation",&rotation.x,0.1f);
                ImGui::DragFloat3("scale",&scale.x,0.1f,0.0001);
                position_change=position-transform.position();
                rotation_change=rotation-transform.eulerRotation();
                scale_change=scale-transform.scale();
            }
            ImGui::EndChild();
            for (auto e:selected_entities) {
                e->transform.translate(position_change);
                e->transform.rotate(quat(rotation_change));
                //e->transform.scale(scale_change);
            }
        }
    }
    ImGui::End();
}

//
// Created by User on 11-Mar.-2020.
//

#include "SceneTreeWindow.h"
void SceneTreeWindow::createHierachy(Input& input,const std::vector<Entity*>& entities,std::set<Entity*>& selected_entities) const {

    std::list<Entity *> root_entities;
    for (auto e:entities) {
        if (e->getParent() == nullptr) {
            root_entities.push_back(e);
        }
    }
    ImGui::SetNextItemOpen(true);
    if(ImGui::TreeNode("Root"))
    {
        if(ImGui::IsItemClicked())
        {
            selected_entities.clear();
        }
        for (auto root_entity:root_entities) {
            createEntityTree(input,root_entity,selected_entities);
        }
        ImGui::TreePop();
    }

}

void SceneTreeWindow::createEntityTree(Input& input,Entity *entity,std::set<Entity*>& selected_entities) const {
    bool is_selected = selected_entities.find(entity) != selected_entities.end();
    if (entity->getChildren().size() == 0) {
        ImGui::Bullet();
        ImGui::SameLine();
        ImGui::Selectable(entity->getName().c_str(), is_selected);
        handleClick(is_selected,input,entity,selected_entities);
    } else {
        ImVec2 pos = ImGui::GetCursorScreenPos();
        ImU32 col = ImColor(ImGui::GetStyle().Colors[ImGuiCol_TextSelectedBg]);
        //if tree node is open

        if (ImGui::TreeNode(entity->getName().c_str())) {
            handleClick(is_selected,input,entity,selected_entities);
            for (auto child:entity->getChildren()) {
                createEntityTree(input,child,selected_entities);
            }
            ImGui::TreePop();
        }
        //create rect to indicate selection
        if (is_selected)
        {
            ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + ImGui::GetContentRegionMax().x,
                                                                  pos.y + ImGui::GetTextLineHeight()), col, false);
        }

    }
}
void SceneTreeWindow::handleClick(bool is_selected,Input &input, Entity *entity, std::set<Entity *> &selected_entities) const{
    if (ImGui::IsItemClicked()&&(ImGui::GetMousePos().x - ImGui::GetItemRectMin().x) > ImGui::GetTreeNodeToLabelSpacing()) {
        //if multiselect
        if (input.isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
            if(is_selected)
            {
                selected_entities.erase(entity);
            }
            if(!is_selected)
            {
                selected_entities.insert(entity);
            }
        }
            //no multiselect
        else
        {
            selected_entities.clear();
            selected_entities.insert(entity);
        }
    }
}
void SceneTreeWindow::update(Input& input,ImGuiID dockspace_id,const std::vector<Entity*>& entities,std::set<Entity *>& selected_entities) {
    ImGui::SetNextWindowDockID(dockspace_id, ImGuiCond_FirstUseEver);
    ImGui::Begin("Scene");
    createHierachy(input,entities,selected_entities);
    ImGui::End();
}



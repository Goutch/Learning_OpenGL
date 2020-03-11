//
// Created by User on 11-Mar.-2020.
//

#pragma once

#include <API_ALL.h>
class SceneTreeWindow {
    void createHierachy(Input& input,const std::vector<Entity*>& entities,std::set<Entity*>& selected_entities) const;
    void createEntityTree(Input& input,Entity *entity,std::set<Entity*>& selected_entities) const;
    void handleClick(bool is_selected,Input& input,Entity *entity,std::set<Entity*>& selected_entities) const;
public:
    void update(Input& input,ImGuiID dockspace_id,const std::vector<Entity*>& entities,std::set<Entity*>& selected_entities);
};



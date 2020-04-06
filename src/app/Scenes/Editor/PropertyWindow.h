#pragma once

#include <API_ALL.h>
class PropertyWindow {
    Entity* current_entity;
    vec3 position=vec3(0);
    vec3 rotation=vec3(0);
    vec3 scale=vec3(1);
public:
    void update(ImGuiID dockpace_id,std::set<Entity*>& selected_entities);
};

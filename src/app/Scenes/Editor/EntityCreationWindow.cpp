//
// Created by User on 12-Mar.-2020.
//

#include "EntityCreationWindow.h"
#include "CameraWindow.h"

#include <API_ALL.h>
EntityCreationWindow::EntityCreationWindow(Scene *scene) {
    material=new LightMaterial(shader,*scene);
}
void EntityCreationWindow::update(Scene *scene, Entity *parent,std::set<Entity*>& selected_entities, ImGuiID dockspace_id,
                                  std::map<Camera *, CameraWindow *>& cameras) {
    ImGui::SetNextWindowDockID(dockspace_id, ImGuiCond_FirstUseEver);
    Renderer& renderer=scene->getRenderer();
    ImGui::Begin("Create");
    {
        if (ImGui::Button("Cube")) {
            Entity *entity;
            scene->instantiate(entity = new MeshRenderer(renderer.CUBE, *material, vec3(0, 0, 0),
                                                         vec3(0, 0, 0), vec3(1, 1, 1)));
            entity->setName("Entity: " +
                            std::to_string(scene->getEntities().size()));
            if(parent!= nullptr)
                entity->setParent(parent);
        }

        if (ImGui::Button("Sphere")) {
            Entity *entity;
            scene->instantiate(
                    entity = new MeshRenderer(renderer.SPHERE, *material, vec3(0, 0, 0),
                                              vec3(0, 0, 0), vec3(1, 1, 1))
            );
            entity->setName("Entity: " + std::to_string(scene->getEntities().size()));
            if(parent!= nullptr)
                entity->setParent(parent);

        }
        if (ImGui::Button("Light")) {
            if (PointLight::getInstances().size() < 4) {
                PointLight *entity;
                scene->instantiate(entity = new PointLight(Color(1, 1, 1), 10, vec3(0))
                );
                entity->setName("Light: " + std::to_string(PointLight::getInstances().size() + 1));
                if(parent!= nullptr)
                    entity->setParent(parent);

            }

        }
        if (ImGui::Button("Camera")) {
            Camera *entity;
            scene->instantiate(entity = new Camera());
            entity->setName("Camera: " +std::to_string(cameras.size() + 1));
            cameras.emplace(entity,new CameraWindow());
            if(parent!= nullptr)
                entity->setParent(parent);

        }
        if (ImGui::Button("Delete")) {
            for (auto entity: selected_entities) {
                if(entity->getName()[0]=='C')
                {
                    cameras.erase((Camera*)entity);
                }
                scene->destroy(entity);
            }
            selected_entities.clear();
        }
    }
    ImGui::End();
}


EntityCreationWindow::~EntityCreationWindow() {
    delete material;
}




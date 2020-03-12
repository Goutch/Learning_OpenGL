
#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>

#include <imgui.h>

#include "API_ALL.h"

Editor::Editor(Scene *scene) {
    this->current_scene = scene;
}

Editor::Editor() {
    current_scene = new Scene();
}

Editor::~Editor() {
    for (auto c:cameras) {
        delete c.second;
    }
    delete current_scene_canvas;
    delete current_scene;
    delete material;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Input &input) {

    Scene::init(canvas, renderer, input);
    current_scene_canvas = new Canvas(canvas, renderer.DEFAULT_2D_SHADER, canvas.getPixelWidth() / 2,
                                      canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                      canvas.getPixelHeight() / 4);
    current_scene->init(*current_scene_canvas, renderer, input);


    current_scene->getCamera().transform.position(vec3(0, 0, 3));
    current_scene->getCamera().setName("Camera 1");
    cameras.emplace(&current_scene->getCamera(),new CameraWindow());
    material = new LightMaterial(shader, *current_scene);
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);

    ImGuiID dockspaceID = 0;
    float h, w;
    w = canvas->getPixelWidth();
    h = canvas->getPixelHeight();
    Scene::draw();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(w, h), 0);
    ImGui::Begin("EDITOR");
    {
        dockspaceID = ImGui::GetID("HUB_DockSpace");
        ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f),
                         0/* ImGuiDockNodeFlags_None|ImGuiDockNodeFlags_PassthruCentralNode|ImGuiDockNodeFlags_NoResize*/);
    }
    ImGui::End();
    scene_tree.update(*input, dockspaceID, current_scene->getEntities(), selected_entities);
    properties.update(dockspaceID, selected_entities);
    for (auto &cam:cameras) {
        //todo: handle deleted cameras
        cam.second->update(current_scene, renderer, input, cam.first, dockspaceID);
    }


    ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
    ImGui::Begin("Create");
    {
        if (ImGui::Button("Cube")) {
            Entity *entity;
            current_scene->instantiate(entity = new MeshRenderer(renderer->CUBE, *material, vec3(0, 0, 0),
                                                                 vec3(0, 0, 0), vec3(1, 1, 1)));
            entity->setName("Entity: " +
                            std::to_string(current_scene->getEntities().size()));
            if (selected_entities.size() == 1) {
                entity->setParent(*selected_entities.begin());
            }
        }

        if (ImGui::Button("Sphere")) {
            Entity *entity;
            current_scene->
                    instantiate(
                    entity = new MeshRenderer(renderer->SPHERE, *material, vec3(0, 0, 0),
                                              vec3(0, 0, 0), vec3(1, 1, 1))
            );
            entity->setName("Entity: " + std::to_string(current_scene->getEntities().size()));
            if (selected_entities.size() == 1) {
                entity->setParent(*selected_entities.begin());
            }

        }
        if (ImGui::Button("Light")) {
            if (PointLight::getInstances().size() < 4) {
                PointLight *entity;
                current_scene->
                        instantiate(
                        entity = new PointLight(Color(1, 1, 1), 10, vec3(0))
                );
                entity->setName("Light: " + PointLight::getInstances().size() + 1);
                if (selected_entities.size() == 1) {
                    entity->setParent(*selected_entities.begin());
                }

            }

        }
        if (ImGui::Button("Camera")) {
            Camera *entity;
            current_scene->
                    instantiate(
                    entity = new Camera()
            );
            entity->setName("Camera: " +
                            std::to_string(cameras.size() + 1));
            if (selected_entities.size() == 1) {
                entity->setParent(*selected_entities.begin());
            }
            cameras.emplace(entity,new CameraWindow());
        }
        if (ImGui::Button("Delete")) {
            for (auto entity: selected_entities) {
                current_scene->destroy(entity);
            }
            selected_entities.clear();
        }
    }
    ImGui::End();
}


void createTree(const std::vector<Entity *> &entities, Entity *parent, int &index,
                std::set<Entity *> &selectedEntities, Scene *current_scene, float &posX, float &posY,
                float &posZ, float &rotX, float &rotY, float &rotZ, float &sizeX, float &sizeY, float &sizeZ) {

    for (auto iter : entities) {
        if (iter == parent) {
            if (ImGui::TreeNode((void *) (intptr_t) index, iter->getName().c_str(), index++)) {
                if (ImGui::IsItemClicked()) {
                    if (!current_scene->getInput().isKeyDown(GLFW_KEY_LEFT_CONTROL))
                        selectedEntities.clear();
                    selectedEntities.emplace(iter);

                    if (!selectedEntities.empty()) {
                        vec3 pos = (*(selectedEntities.begin()++))->transform.localPosition();
                        posX = pos[0];
                        posY = pos[1];
                        posZ = pos[2];
                        vec3 rot = (*(selectedEntities.begin()++))->transform.eulerRotation();
                        rotX = rot[0];
                        rotY = rot[1];
                        rotZ = rot[2];
                        vec3 size = (*(selectedEntities.begin()++))->transform.scale();
                        sizeX = size[0];
                        sizeY = size[1];
                        sizeZ = size[2];
                    }
                }
                createTree(entities, iter, index, selectedEntities, current_scene, posX, posY, posZ, rotX, rotY, rotZ,
                           sizeX, sizeY, sizeZ);
                ImGui::TreePop();
            }
        }
    }
}











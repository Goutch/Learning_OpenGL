//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Canvas/Rect.h>
#include <Entities/Canvas/Line.h>
#include <imgui.h>
#include <imgui_demo.cpp>
#include "Core/Input.h"
Editor::Editor(SpacialScene* scene) {
    this->current_scene=scene;
}
Editor::Editor() {
    current_scene=new SpacialScene();
}

Editor::~Editor() {
    delete current_scene_canvas;
    delete current_scene;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    current_scene_canvas = new Canvas(canvas, renderer.DEFAULT_CANVAS_SHADER, canvas.getPixelWidth() / 2,
                                      canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                      canvas.getPixelHeight() / 4);
    current_scene->init(*current_scene_canvas, renderer, input);;
}
void Editor::setScene(SpacialScene* scene) {
    this->current_scene=scene;
    current_scene->init(*current_scene_canvas, *renderer, *input);
}
void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
    for(auto iter : selectedEntities) {
        (*iter).transform.position(vec3(posX, posY, posZ));
        quat quaternion = quat(vec3(rotX, rotY, rotZ));
        //(*iter).transform.rotate(quaternion);
        if(sizeX != 0 && sizeY != 0 && sizeZ != 0)
            (*iter).transform.scale(vec3(sizeX, sizeY, sizeZ));
    }
}

void createTree(const std::vector<SpacialEntity*>& vector, Transform* parent, int& index, std::set<SpacialEntity*> &selectedEntities, SpacialScene* current_scene, float& posX, float& posY, float& posZ) {
    for(auto iter : vector) {
        if(iter->transform.parent == parent) {
            if (ImGui::TreeNode((void*)(intptr_t)index, iter->getName().c_str(), index++))
            {
                if(ImGui::IsItemClicked()) {
                    vec3 pos = iter->transform.localPosition();
                    posX = pos[0];
                    posY = pos[1];
                    posZ = pos[2];

                    if(!current_scene->getInput().isKeyDown(GLFW_KEY_LEFT_CONTROL))
                        selectedEntities.clear();
                    selectedEntities.emplace(iter);
                }
                createTree(vector, &iter->transform, index, selectedEntities, current_scene, posX, posY, posZ);
                ImGui::TreePop();
            }
        }
    }
}

void Editor::draw() const {
    current_scene->draw();
    current_scene->getCanvas().getFrameBuffer().bind();
    renderer->clear();
    current_scene->getCanvas().getFrameBuffer().unbind();
    current_scene->render();

    ImGuiID dockspaceID = 0;
    float h,w;
    w=canvas->getPixelWidth();
    h=canvas->getPixelHeight();
    Scene::draw();
    ImGui::SetNextWindowPos(ImVec2(0,0));
    ImGui::SetNextWindowSize(ImVec2(w,h),0);
    ImGui::Begin("EDITOR");
    {
        dockspaceID = ImGui::GetID("HUB_DockSpace");
        ImGui::DockSpace(dockspaceID , ImVec2(0.0f, 0.0f),0/* ImGuiDockNodeFlags_None|ImGuiDockNodeFlags_PassthruCentralNode|ImGuiDockNodeFlags_NoResize*/);
    }
    ImGui::End();

    ImGui::SetNextWindowDockID(dockspaceID , ImGuiCond_FirstUseEver);
    ImGui::Begin("Scene rendering");
    {
        ImVec2 vMin = ImGui::GetWindowContentRegionMin();
        ImVec2 vMax = ImGui::GetWindowContentRegionMax();
        if(vMax.x!=current_scene_canvas->getPixelWidth()||
            vMax.y!=current_scene_canvas->getPixelHeight())
            current_scene_canvas->setSize(vMax.x,vMax.y);
        vMin.x += ImGui::GetWindowPos().x;
        vMin.y += ImGui::GetWindowPos().y;
        vMax.x += ImGui::GetWindowPos().x;
        vMax.y += ImGui::GetWindowPos().y;
        ImGui::GetWindowDrawList()->AddImage(
                (void *) current_scene_canvas->getFrameBuffer().getTexture().getID(),
                vMin,
                vMax,
                ImVec2(0, 1),
                ImVec2(1, 0));
    }
    ImGui::End();

    ImGui::SetNextWindowDockID(dockspaceID , ImGuiCond_FirstUseEver);
    ImGui::Begin("Transform") ;
    {
        ImGui::PushItemWidth(100);
        if(!selectedEntities.empty()) {
            vec3 pos = (*(selectedEntities.begin()++))->transform.localPosition();
            posX = pos[0];
            posY = pos[1];
            posZ = pos[2];
            vec3 rot = (*(selectedEntities.begin()++))->transform.eulerRotation();
            rotX = rot[0];
            rotY = rot[1];
            rotZ = rot[2];
        }

        ImGui::SliderFloat("x", &posX, -10, 10); ImGui::SameLine();
        ImGui::SliderFloat("y", &posY, -10, 10); ImGui::SameLine();
        ImGui::SliderFloat("z", &posZ, -10, 10);
        ImGui::SliderFloat("rot x", &rotX, -10, 10);ImGui::SameLine();
        ImGui::SliderFloat("rot y", &rotY, -10, 10);ImGui::SameLine();
        ImGui::SliderFloat("rot z", &rotZ, -10, 10);
        ImGui::SliderFloat("size x", &sizeX, -10, 10);ImGui::SameLine();
        ImGui::SliderFloat("size y", &sizeY, -10, 10);ImGui::SameLine();
        ImGui::SliderFloat("size z", &sizeZ, -10, 10);
    }
    ImGui::End();

    ImGui::SetNextWindowDockID(dockspaceID , ImGuiCond_FirstUseEver);
    ImGui::Begin("Create things");
    {
        std::list<SpacialEntity*> parents;
        for(auto iter : current_scene->getSpacialEntities()) {
            if(iter->transform.parent == nullptr)
                parents.push_back(iter);
        }
        if (ImGui::TreeNode("Elements")) {
            int index = 0;
            createTree(current_scene->getSpacialEntities(), nullptr, index, selectedEntities, current_scene, posX, posY, posZ);
            ImGui::TreePop();
        }

        if(ImGui::Button("Cube")) {
            SpacialEntity* entity;
            current_scene->addEntity(entity = new MeshRenderer(renderer->CUBE, renderer->DEFAULT_SPACIAL_MATERIAL, vec3(0, 0, 0), vec3(0), vec3(1, 1, 1)));
            entity->setName("Entity: " + std::to_string(current_scene->getSpacialEntities().size()));
            if(current_scene->getSpacialEntities().size() > 1)
                entity->transform.parent = &current_scene->getSpacialEntities()[0]->transform;
        }

        if(ImGui::Button("Sphere")) {
            SpacialEntity* entity;
            current_scene->addEntity(entity = new MeshRenderer(renderer->SPHERE, renderer->DEFAULT_SPACIAL_MATERIAL, vec3(0, 0, 0), vec3(0), vec3(1, 1, 1)));
            entity->setName("Entity: " + std::to_string(current_scene->getSpacialEntities().size()));
            if(current_scene->getSpacialEntities().size() > 1)
                entity->transform.parent = &current_scene->getSpacialEntities()[0]->transform;
        }
        std::string text;
        for(auto iter : selectedEntities)
            text+=iter->getName();
        if(!selectedEntities.empty())
            ImGui::Text(text.c_str());
    }
    ImGui::End();
}










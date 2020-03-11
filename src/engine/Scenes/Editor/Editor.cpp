
#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/MeshRenderer.h>

#include <imgui.h>
#include <imgui_demo.cpp>
#include <Core/Log.h>
#include "Core/Input.h"
#include "API_ALL.h"

Editor::Editor(Scene *scene) {
    this->current_scene = scene;
}

Editor::Editor() {
    current_scene = new Scene();
}

Editor::~Editor() {
    for (int i = 0; i < cameras_canvas.size(); ++i) {
        delete cameras_canvas[i];
    }
    cameras_canvas.clear();
    delete current_scene;
    delete material;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Input &input) {

    Scene::init(canvas, renderer, input);
    cameras_canvas.push_back(new Canvas(canvas, renderer.DEFAULT_2D_SHADER, canvas.getPixelWidth() / 2,
                                        canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                        canvas.getPixelHeight() / 4));
    current_scene->init(*cameras_canvas[0], renderer, input);


    current_scene->getCamera().transform.position(vec3(0, 0, 3));
    current_scene->getCamera().setName("Camera 1");
    cameras.push_back(&current_scene->getCamera());
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
    scene_tree.update(*input,dockspaceID,current_scene->getEntities(),selected_entities);
    properties.update(dockspaceID, selected_entities);

    for (int i = 0; i < cameras.size(); ++i) {
        ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
        ImGui::Begin(cameras[i]->getName().c_str());
        {
            current_scene->draw();
            cameras_canvas[i]->getFrameBuffer().bind();
            renderer->clear();
            cameras_canvas[i]->getFrameBuffer().unbind();
            current_scene->setCamera(*cameras[i]);
            renderer->render(cameras_canvas[i]->getFrameBuffer(), cameras[i]->getProjectionMatrix(),
                             cameras[i]->getViewMatrix());

            Camera::ProjectionMode mode = current_scene->getCamera().getProjectionMode();
            ImGui::BeginChild("Projection");
            if (ImGui::Button(mode == Camera::ProjectionMode::PERSPECTIVE ? "Perspective" : "Orthographic")) {
                if (mode == Camera::ORTHOGRAPHIC)
                    current_scene->getCamera().setProjectionPerspective();
                else
                    current_scene->getCamera().setProjectionOrtho(10, 10);
            }
            ImGui::EndChild();
            ImVec2 vMin = ImGui::GetWindowContentRegionMin();
            ImVec2 vMax = ImGui::GetWindowContentRegionMax();
            if (vMax.x != cameras_canvas[i]->getPixelWidth() ||
                vMax.y != cameras_canvas[i]->getPixelHeight())
                cameras_canvas[i]->setSize(vMax.x, vMax.y);
            vMin.x += ImGui::GetWindowPos().x;
            vMin.y += ImGui::GetWindowPos().y;
            vMax.x += ImGui::GetWindowPos().x;
            vMax.y += ImGui::GetWindowPos().y;
            ImGui::GetWindowDrawList()->AddImage(
                    (void *) cameras_canvas[i]->getFrameBuffer().getTexture().getID(),
                    vMin,
                    vMax,
                    ImVec2(0, 1),
                    ImVec2(1, 0));
        }
        ImGui::End();
    }

   // ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
    /*ImGui::Begin("Properties");
    {
        if (!selected_entities.empty()) {
            ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
            ImGui::BeginChild("Transform");
            {
                bool sameposX = true;
                bool samerotX = true;
                bool samesizeX = true;
                bool sameposY = true;
                bool samerotY = true;
                bool samesizeY = true;
                bool sameposZ = true;
                bool samerotZ = true;
                bool samesizeZ = true;

                if (selected_entities.size() > 1)
                    for (auto iter : selected_entities) {
                        vec3 pos = (*(selected_entities.begin()++))->transform.localPosition();
                        if (std::abs(iter->transform.position()[0] - pos[0]) > 0.0001f)
                            sameposX = false;
                        if (std::abs(iter->transform.position()[1] - pos[1]) > 0.0001f)
                            sameposY = false;
                        if (std::abs(iter->transform.position()[2] - pos[2]) > 0.0001f)
                            sameposZ = false;

                        vec3 rot = (*(selected_entities.begin()++))->transform.eulerRotation();
                        if (std::abs(iter->transform.rotation()[0] - rot[0]) > 0.0001f)
                            samerotX = false;
                        if (std::abs(iter->transform.rotation()[1] - rot[1]) > 0.0001f)
                            samerotY = false;
                        if (std::abs(iter->transform.rotation()[2] - rot[2]) > 0.0001f)
                            samerotZ = false;

                        vec3 size = (*(selected_entities.begin()++))->transform.scale();
                        if (std::abs(iter->transform.scale()[0] - size[0]) > 0.0001f)
                            samesizeX = false;
                        if (std::abs(iter->transform.scale()[1] - size[1]) > 0.0001f)
                            samesizeY = false;
                        if (std::abs(iter->transform.scale()[2] - size[2]) > 0.0001f)
                            samesizeZ = false;
                    }

                for (auto iter : selected_entities) {
                    vec3 pos = iter->transform.localPosition();
                    if (sameposX)
                        pos[0] = posX;
                    if (sameposY)
                        pos[1] = posY;
                    if (sameposZ)
                        pos[2] = posZ;

                    (*iter).transform.position(pos);
                    vec3 rot = iter->transform.eulerRotation();
                    if (samerotX)
                        rot[0] = rotX;
                    if (samerotY)
                        rot[1] = rotY;
                    if (samerotZ)
                        rot[2] = rotZ;

                    quat quaternion = quat(rot);
                    if (activeRotation)
                        (*iter).transform.rotation(quaternion);

                    vec3 size = iter->transform.scale();
                    if (samesizeX)
                        size[0] = sizeX;
                    if (samesizeY)
                        size[1] = sizeY;
                    if (samesizeZ)
                        size[2] = sizeZ;

                    if (sizeX != 0 && sizeY != 0 && sizeZ != 0)
                        (*iter).transform.scale(size);
                }

                ImGui::PushItemWidth(100);
                if (!selected_entities.empty()) {
                    vec3 pos = (*(selected_entities.begin()++))->transform.localPosition();
                    posX = pos[0];
                    posY = pos[1];
                    posZ = pos[2];
                    vec3 rot = (*(selected_entities.begin()++))->transform.eulerRotation();
                    rotX = rot[0];
                    rotY = rot[1];
                    rotZ = rot[2];

                    vec3 size = (*(selected_entities.begin()++))->transform.scale();
                    sizeX = size[0];
                    sizeY = size[1];
                    sizeZ = size[2];
                }

                ImGui::InputFloat("x", &posX, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("y", &posY, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("z", &posZ, 0.1f, 0.1f);
                ImGui::Checkbox("Active rotation", &activeRotation);
                ImGui::InputFloat("rot x", &rotX, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("rot y", &rotY, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("rot z", &rotZ, 0.1f, 0.1f);
                ImGui::InputFloat("size x", &sizeX, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("size y", &sizeY, 0.1f, 0.1f);
                ImGui::SameLine();
                ImGui::InputFloat("size z", &sizeZ, 0.1f, 0.1f);
            }
            ImGui::EndChild();
        }
    }

    ImGui::End();*/

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
                entity->setName("Light: " +
                                std::to_string(lightCount
                                               + 1));
                if (selected_entities.size() == 1) {
                    entity->setParent(*selected_entities.begin());
                }
                lightCount++;
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
            cameras_canvas.push_back(new Canvas(*canvas, renderer->DEFAULT_2D_SHADER, 1, 1));
            cameras.push_back(entity);
        }
        if (ImGui::Button("Delete")) {
            for (auto entity: selected_entities) {
                if (entity->getName()[0] == 'C') {
                    for (int i = 0; i < cameras.size(); ++i) {
                        if (cameras[i]->getName() == entity->getName()) {
                            cameras_canvas.erase(cameras_canvas.begin() + i);
                            cameras.erase(cameras.begin() + i);
                            current_scene->destroy(entity);
                        }
                    }
                } else {
                    current_scene->
                            destroy(entity);
                }
            }
            selected_entities.clear();
        }
        std::string text;
        for (auto iter: selected_entities)
            text += iter->getName();
        if (!selected_entities.empty()) { ImGui::Text(text.c_str()); }

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











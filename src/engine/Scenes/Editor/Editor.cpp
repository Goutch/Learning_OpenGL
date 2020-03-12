
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
    delete entity_creator;
    delete current_scene_canvas;
    delete current_scene;

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

    entity_creator=new EntityCreationWindow(current_scene);
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
    entity_creator->update(current_scene,(selected_entities.empty()? nullptr:*selected_entities.begin()),selected_entities,dockspaceID,cameras);
    for (auto &cam:cameras) {
        //todo: handle deleted cameras
        cam.second->update(current_scene, renderer, input, cam.first, dockspaceID);
    }
}








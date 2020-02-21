//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Canvas/Rect.h>
#include <Entities/Canvas/Line.h>
#include <imgui.h>
Editor::Editor(Scene &scene) {
    this->current_scene = &scene;
}

Editor::~Editor() {
    delete current_scene_canvas;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    current_scene_canvas = new Canvas(canvas, renderer.DEFAULT_CANVAS_SHADER, canvas.getPixelWidth() / 2,
                                      canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                      canvas.getPixelHeight() / 4);
    current_scene->init(*current_scene_canvas, renderer, window);

    secondary_material.setShader(renderer.DEFAULT_CANVAS_SHADER);
    secondary_material.setColor(Color(0.5, 0.5, 0.5));

    primary_material.setShader(renderer.DEFAULT_CANVAS_SHADER);
    primary_material.setColor(Color(1, 1, 1));
    //addEntity(new Rect(vec2(canvas.getPixelWidth() / 2, canvas.getPixelHeight() / 2),
                       //vec2(canvas.getPixelWidth(), canvas.getPixelHeight()), secondary_material));
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}

void Editor::draw() const {
    current_scene->draw();
    current_scene->render();
    float h,w;
    w=canvas->getPixelWidth();
    h=canvas->getPixelHeight();
    Scene::draw();
    ImGui::SetNextWindowSize(ImVec2((w/2)+10, (h/2)+50),0);
    ImGui::Begin("Scene rendering");
    {
        ImGui::GetWindowDrawList()->AddImage(
                (void *)current_scene_canvas->getFrameBuffer().getTexture().getID(),
                ImVec2(ImGui::GetCursorScreenPos()),
                ImVec2(ImGui::GetCursorScreenPos().x + w/2,ImGui::GetCursorScreenPos().y + h/2),
                       ImVec2(0, 1),
                ImVec2(1, 0));
    }
    ImGui::End();
}

void Editor::destroy() {
    current_scene->destroy();
    Scene::destroy();
}





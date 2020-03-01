//
// Created by Simon on 2020-02-04.
//

#include "ApplicationDrawing2D.h"
#include <Core/Rendering/Renderer.h>

#include "Entities/Canvas/Text.h"
#include <Geometry/Geometry.h>

#include <Core/Window.h>
#include "imgui.h"
#include <Core/Canvas.h>
#include <Core/Log.h>
#include <Core/Input.h>

void ApplicationDrawing2D::draw() const {
    Scene::draw();

    ImGui::Begin("Properties");
    {
        ImGui::ColorPicker4("Background Color", &background_color.r);
        ImGui::ColorPicker4("Fill Color", &fill_color.r);
        ImGui::InputText("Line Width", &line_width, 4);
    }
    ImGui::End();
}

void ApplicationDrawing2D::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
}

void ApplicationDrawing2D::update(float delta) {
    Scene::update(delta);

    double x = 0,y = 0;
    input->getMousePosition(x, y);
    if(input->getMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
        Log::message("x: " + std::to_string(x) + "y: " + std::to_string(y));
    }
}



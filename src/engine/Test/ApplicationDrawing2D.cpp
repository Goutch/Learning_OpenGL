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
#include <Entities/Canvas/Point.h>

void ApplicationDrawing2D::draw() const {
    Scene::draw();

    ImGui::Begin("Properties");
    {
        ImGui::ColorPicker4("Background Color", &background_color.r);
        ImGui::ColorPicker4("Fill Color", &fill_color.r);
        ImGui::InputText("Line Width", line_width, 4);

        ImGui::RadioButton("point", &tool, 0);
        ImGui::RadioButton("ligne", &tool, 1);
        ImGui::RadioButton("rectangle", &tool, 2);
        ImGui::RadioButton("triangle", &tool, 3);
        ImGui::RadioButton("ellipse", &tool, 4);
    }
    ImGui::End();
}

void ApplicationDrawing2D::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);

    windowHeight = canvas.getPixelHeight();
}

void ApplicationDrawing2D::update(float delta) {
    Scene::update(delta);

    double x = 0,y = 0;
    input->getMousePosition(x, y);
    if(input->getMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
        if(tools[tool] != nullptr)
            tools[tool]->onMousePressed(x, y, *this);
    }

    if(input->getMouseButtonReleased(GLFW_MOUSE_BUTTON_1)) {
        if(tools[tool] != nullptr)
            tools[tool]->onMouseReleased(x, y, *this);
    }
}


unsigned int ApplicationDrawing2D::getWindowHeight() const {
    return windowHeight;
}



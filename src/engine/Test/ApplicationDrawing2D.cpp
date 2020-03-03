//
// Created by Simon on 2020-02-04.
//
#include <filesystem>

#include "ApplicationDrawing2D.h"
#include <Core/Rendering/Renderer.h>
#include "Entities/Canvas/Text.h"
#include <Geometry/Geometry.h>

#include <Core/Window.h>
#include "imgui.h"
#include <Core/Canvas.h>
#include <Core/Log.h>
#include <Core/Input.h>
#include <Entities/Canvas/Ellipse.h>
#include "imgui_demo.cpp"

void ApplicationDrawing2D::draw() const {
    Scene::draw();
    glClearColor(background_color.r, background_color.g, background_color.b, background_color.a);
    ImGui::Begin("Properties");
    {
        ImGui::ColorPicker4("Background Color", &background_color.r);
        if(ImGui::ColorPicker4("Fill Color", &fill_color.r)) {
            const_cast<FontMaterial*>(font)->setColor(fill_color);
        }
        ImGui::InputText("Line Width", line_width, 4);
        ImGui::RadioButton("point", &tool, 0);
        ImGui::RadioButton("rectangle", &tool, 1);
        ImGui::RadioButton("ellipse", &tool, 2);
        ImGui::RadioButton("text", &tool, 3);
        ImGui::RadioButton("image", &tool, 4);
        ImGui::InputText("Font path", font_path, 32);
        ImGui::InputText("Font width (tile)", font_width, 32);
        ImGui::InputText("Font height (tile)", font_height, 32);
        if(ImGui::Button("Change font")) {
            int font_width_int = std::stoi(font_width), font_height_int = std::stoi(font_height);
            delete font;
            font = new FontMaterial(shader, font_path,font_width_int,font_height_int);
        }
        ImGui::InputText("Texture path", texture_path, 32);
        if(ImGui::Button("Change texture")) {
            delete texture;
            texture = new Texture(texture_path);
            textureMat.setTexture(*texture);
        }
    }
    ImGui::End();
}

void ApplicationDrawing2D::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    input.subscribeKey(*this);
    windowHeight = canvas.getPixelHeight();
    textureMat.setShader(renderer.DEFAULT_CANVAS_SHADER);
    textureMat.setTexture(*texture);
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

void ApplicationDrawing2D::onKeyPress(int key) {
    if(tools[tool] != nullptr)
        tools[tool]->onKeyPressed(key, *this);
}

void ApplicationDrawing2D::onKeyReleased(int key) {
    if(tools[tool] != nullptr)
        tools[tool]->onKeyReleased(key, *this);
}

ApplicationDrawing2D::~ApplicationDrawing2D() {
    input->unsubscribeKey(*this);
    delete font;
    delete texture;
}



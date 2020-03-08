//
// Created by Simon on 2020-02-04.
//
//#include <filesystem>

#include "ApplicationDrawing2D.h"
#include "API_ALL.h"

void ApplicationDrawing2D::draw() const {
    Scene::draw();

    glClearColor(background_color.r, background_color.g, background_color.b, background_color.a);
    ImGui::Begin("Properties");
    {
        ImGui::Checkbox("HSV", &isHSV);
        ImGui::ColorPicker4("Background Color", &background_color.r,
                            isHSV ? ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_PickerHueWheel
                                  : ImGuiColorEditFlags_DisplayRGB);
        if (ImGui::ColorPicker4("Fill Color", &fill_color.r,
                                isHSV ? ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_PickerHueWheel
                                      : ImGuiColorEditFlags_DisplayRGB)) {
            const_cast<FontMaterial *>(font)->setColor(fill_color);
        }
        ImGui::RadioButton("point", &tool, 0);
        ImGui::RadioButton("rectangle", &tool, 1);
        ImGui::RadioButton("ellipse", &tool, 2);
        ImGui::RadioButton("text", &tool, 3);
        ImGui::RadioButton("image", &tool, 4);
        ImGui::InputText("Font path", font_path, 32);
        ImGui::InputText("Font width (tile)", font_width, 32);
        ImGui::InputText("Font height (tile)", font_height, 32);
        if (ImGui::Button("Change font")) {
            int font_width_int = std::stoi(font_width), font_height_int = std::stoi(font_height);
            delete font;
            font = new FontMaterial(shader, font_path, font_width_int, font_height_int);
        }
        ImGui::InputText("Texture path", texture_path, 32);
        if (ImGui::Button("Change texture")) {
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
    if(tools[tool] != nullptr)
    {
        switch(tool){
            case 0:
                input->setCursor(Input::HAND);
                break;
            case 1:
                input->setCursor(Input::CROSSHAIR);
                break;
            case 2:
                input->setCursor(Input::CROSSHAIR);
                break;
            case 3://Text
                input->setCursor(Input::IBEAM);
                break;
            case 4://image
                input->setCursor(Input::HAND);
                break;
        }
    } else{
        input->setCursor(Input::ARROW);
    }
    double x = 0, y = 0;
    input->getMousePosition(x, y);
    if (input->getMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
        if (tools[tool] != nullptr)
            tools[tool]->onMousePressed(x, y, *this);
    }

    if (input->getMouseButtonReleased(GLFW_MOUSE_BUTTON_1)) {
        if (tools[tool] != nullptr)
            tools[tool]->onMouseReleased(x, y, *this);
    }
}


unsigned int ApplicationDrawing2D::getWindowHeight() const {
    return windowHeight;
}

void ApplicationDrawing2D::onKeyPress(int key) {
    if (tools[tool] != nullptr)
        tools[tool]->onKeyPressed(key, *this);
}

void ApplicationDrawing2D::onKeyReleased(int key) {
    if (tools[tool] != nullptr)
        tools[tool]->onKeyReleased(key, *this);
}

ApplicationDrawing2D::~ApplicationDrawing2D() {
    input->unsubscribeKey(*this);
    delete font;
    delete texture;
}



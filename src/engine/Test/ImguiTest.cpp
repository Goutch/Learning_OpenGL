//
// Created by User on 19-Feb.-2020.
//

#include "ImguiTest.h"
#include "imgui.h"
#include <Core/Rendering/Renderer.h>
void ImguiTest::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);

}

void ImguiTest::draw() const {
    Scene::draw();
    bool my_tool_active;
    // Create a window called "My First Tool", with a menu bar.
    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { my_tool_active = false; }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

// Edit a color (stored as ~4 floats)

    ImGui::ColorEdit4("Color", &color.r);


// Plot some values
    const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
    ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

// Display contents in a scrolling region
    ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
    ImGui::End();
    renderer->drawRect(100,100,100,100,color);
}

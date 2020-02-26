#pragma once

#include <API/API.h>

class VK_API :API{
    void init() override;

    GLFWwindow *createWindow(std::string title, int width, int height) override;

    void terminate() override;
};


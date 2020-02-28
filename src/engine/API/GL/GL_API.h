#pragma once

#include <API/API.h>
class GL_API:public API {

    void init() override;
    void terminate() override;
public:
    ~GL_API();
    GLFWwindow *createWindow(std::string title, int width, int height) override;
};

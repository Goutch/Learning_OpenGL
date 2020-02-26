#pragma once

class GLFWwindow;

#include <string>
class API{
public:
    virtual void init()=0;
    virtual GLFWwindow* createWindow(std::string title, int width, int height)=0;
    virtual void terminate()=0;

};

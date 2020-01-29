#pragma once

class Window;
class WindowResizeListener{
public:
    virtual void onWindowSizeChange(unsigned int width, unsigned int height)=0;
};

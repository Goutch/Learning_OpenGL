#pragma once

class Window;
class WindowSizeListener{
public:
    virtual void onWindowSizeChange(int width,int height)=0;
};

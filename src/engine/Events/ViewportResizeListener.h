#pragma once

class Window;
class ViewportResizeListener{
public:
    virtual void onViewportSizeChange(int width, int height)=0;
};

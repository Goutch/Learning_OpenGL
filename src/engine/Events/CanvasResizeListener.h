#pragma once


class CanvasResizeListener{
public:
    virtual void onViewportSizeChange(unsigned int width, unsigned int height)=0;
};

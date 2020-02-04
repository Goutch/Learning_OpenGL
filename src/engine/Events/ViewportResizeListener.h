#pragma once


class ViewportResizeListener{
public:
    virtual void onViewportSizeChange(unsigned int width, unsigned int height)=0;
};

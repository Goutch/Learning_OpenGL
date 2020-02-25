#pragma once

#include "SpacialEntity.h"
#include "Events/CanvasResizeListener.h"
class Canvas;
class Camera : public SpacialEntity , CanvasResizeListener{
public:
    enum ProjectionMode{
        ORTHOGRAPHIC_PIXEL=0,
        ORTHOGRAPHIC_UNITS=1,
        PERSPECTIVE=2
    };
private:
    mat4 projection_matrix;
    const Canvas* canvas;
    float fov=90;
    ProjectionMode projectionMode=PERSPECTIVE;

public:

    Camera(vec3 position=vec3(0), vec3 rotation=vec3(0));
    void setFOV(float fov);
    void calculateProjectionMatrix();
    void setProjectionMode(ProjectionMode projectionMode);
    mat4 getViewMatrix() const;

    void onDestroy(SpacialScene &scene) override;

    void init(SpacialScene &scene) override;
    const mat4 &getProjectionMatrix() const;
    float getFOV() const;
    void onCanvasSizeChange(unsigned int width, unsigned int height) override;

};


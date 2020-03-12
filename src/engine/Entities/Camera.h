#pragma once

#include "Entity.h"
#include "Events/CanvasResizeListener.h"
class Canvas;
class Camera : public Entity , CanvasResizeListener{
public:
    enum ProjectionMode{
        ORTHOGRAPHIC,
        PERSPECTIVE
    };
private:
    mat4 projection_matrix;
    const Canvas* canvas;
    float fov=90;
    ProjectionMode projectionMode=PERSPECTIVE;
    vec2 units=vec2(1);
public:

    Camera(vec3 position=vec3(0), vec3 rotation=vec3(0));
    void setFOV(float fov);
    void setProjectionPerspective(float width,float height);
    void setProjectionOrtho(float width,float height);
    mat4 getViewMatrix() const;

    void onDestroy(Scene &scene) override;
    ProjectionMode getProjectionMode();
    void init(Scene &scene) override;
    const mat4 &getProjectionMatrix() const;
    float getFOV() const;
    void onCanvasSizeChange(unsigned int width, unsigned int height) override;

};


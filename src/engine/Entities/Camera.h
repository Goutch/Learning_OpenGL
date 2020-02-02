#pragma once

#include "Entities/Entity.h"
#include "Events/ViewportResizeListener.h"
class Viewport;
class Camera : public Entity ,ViewportResizeListener{
public:
    enum ProjectionMode{
        ORTHOGRAPHIC_PIXEL=0,
        ORTHOGRAPHIC_UNITS=1,
        PERSPECTIVE=2
    };
private:
    mat4 projection_matrix;
    const Viewport* viewport;
    float fov=90;
    ProjectionMode projectionMode=PERSPECTIVE;



public:

    Camera(const Viewport& viewport,ProjectionMode mode,vec3 position=vec3(0),vec3 rotation=vec3(0));
    Camera(const Viewport& viewport,vec3 position=vec3(0),vec3 rotation=vec3(0));


    void calculateProjectionMatrix();
    void setProjectionMode(ProjectionMode projectionMode);
    mat4 getViewMatrix() const;

    void destroy(Scene &scene) override;

    void init(Scene &scene) override;
    const mat4 &getProjectionMatrix() const;
    mat4 getCameraSpaceMatrix()const;
    float getFOV() const;
    void onViewportSizeChange(unsigned int width, unsigned int height) override;

};


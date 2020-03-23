#pragma once

#include "Entity.h"
#include "Events/CanvasResizeListener.h"
#include <array>
#include "Math/Plane.h"
class BoundingBox;
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
    std::array<Plane,6> frustum_planes;
public:

    Camera(vec3 position=vec3(0), vec3 rotation=vec3(0));
    void setFOV(float fov);
    void setProjectionPerspective(float width,float height);
    void setProjectionOrthographic(float width, float height);
    mat4 getViewMatrix() const;

    void update(float delta, Scene &scene) override;
    void calculateFrustumPlanes();
    void onDestroy(Scene &scene) override;
    ProjectionMode getProjectionMode();
    void init(Scene &scene) override;
    const mat4 &getProjectionMatrix() const;
    float getFOV() const;
    void onCanvasSizeChange(unsigned int width, unsigned int height) override;
    bool isPointInFrustum(const vec3& point) const;
    bool isBoundingBoxInFrustum(const BoundingBox& box) const;
    bool isBoxInFrustum(const vec3& position,const vec3& size) const;
};


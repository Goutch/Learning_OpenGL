
#pragma once

#include <API_ALL.h>
#include <glm/gtx/intersect.hpp>
struct Plane{
    //https://www.youtube.com/watch?v=dB6jyyKhwZE
    //x,y,z is the normal vector
    //w is the distance from the origin
    vec4 equation;
    vec3 normal;
    float d;
    void set(vec4 space){
        this->equation=space;
        this->normal=vec3(space.x,space.y,space.z);
        d=space.w;
    }
    float distance(vec3 point) const{
        return (normal.x * point.x) + (normal.y * point.y) + (normal.z * point.z)+d;
    };
};
class CameraFrustum {
    Camera** pCamera;
    mat4 m;
public:
    virtual ~CameraFrustum();

private:
    std::array<Plane,5> planes;
public:
    enum {
        FRUSTUM_OUTSIDE = 0,
        FRUSTUM_INTERSECT,
        FRUSTUM_INSIDE,
    };
    CameraFrustum(Scene& scene);
    int boxInFrustum(const vec3 &center, float x, float y, float z);
    int PointInFrustum(const vec3 &point);

    void update();
};


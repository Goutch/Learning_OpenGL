#pragma once

class Texture;
#include "Light.h"
class FBO;
class DirectionalLight : public Light {
private:
    FBO* fbo;
    const float range=30;
    const float quality=2048;
    glm::mat4 depth_projection= glm::ortho<float>(-range,range,-range,range,-range,100);

    glm::mat4 light_space_mat;
public:
    DirectionalLight(const Color &color,vec3 position, vec3 rotation);
    DirectionalLight(vec3 position,vec3 rotation);
    DirectionalLight();
    ~DirectionalLight();
    const Texture& shadowMap();
    void calculateShadowMap(SpacialScene &scene);
    const mat4& getLightSpaceMat();
};





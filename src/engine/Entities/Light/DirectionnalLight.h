#pragma once

class Texture;
#include "Light.h"
#include <set>
class FBO;
class DirectionalLight : public Light {
    static std::set<const DirectionalLight*> instances;
public:
    static const std::set<const DirectionalLight*>& getInstances();
private:
    FBO* fbo;
    const float range=30;
    const float quality=2048;
    glm::mat4 depth_projection= glm::ortho<float>(-range,range,-range,range,-range,100);

    mutable glm::mat4 light_space_mat;
public:

    void init(Scene &scene) override;

    DirectionalLight(const Color &color,vec3 position, vec3 rotation);
    DirectionalLight(vec3 position,vec3 rotation);
    DirectionalLight();

    void update(float delta, Scene &scene) override;

    ~DirectionalLight();
    void onDestroy(Scene &scene) override;
    const Texture& getShadowMap() const;
    void calculateShadowMap(const Scene &scene);
    const mat4& getLightSpaceMat() const;

};





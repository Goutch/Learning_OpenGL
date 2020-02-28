#pragma once

#include <Entities/Spacial/Camera.h>
#include "Scene.h"
class PointLight;
class DirectionalLight;
class SpacialScene : public Scene{
protected:
    std::vector<PointLight*> point_lights;
    std::vector<DirectionalLight*> directional_lights;
    Color ambient_light=Color(0.1f,0.1f,0.1f);
    std::vector<SpacialEntity*> spacialEntities;
    Camera camera;
public:

    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;
    void update(float delta) override;
    void render() const override;
    void draw() const override;
    ~SpacialScene();
    void addEntity(SpacialEntity *entity);

    void addLight(PointLight* light);
    void addLight(DirectionalLight* light);
    const std::vector<PointLight*>& getPointLights() const;
    const std::vector<DirectionalLight*>& getDirectionalLights() const;
    const Color& getAmbientLight() const;
    const Camera& getCamera() const;

};

#pragma once

class Camera;

class Input;

class Entity;

class PointLight;

class DirectionalLight;

class Canvas;

class Renderer;

#include "Ressources/Color.h"
#include <vector>

class Scene {
protected:
    std::vector<PointLight *> point_lights;
    std::vector<DirectionalLight *> directional_lights;
    Color ambient_light = Color(0.1f, 0.1f, 0.1f);
    std::vector<Entity *> Entities;
public:
    const std::vector<Entity *> &getSpacialEntities() const;

protected:
    const Canvas *canvas;
    Input *input;
    Renderer *renderer;
    Camera *camera;
public:

    Scene(){};

    virtual void init(const Canvas &canvas, Renderer &renderer, Input &input);

    virtual void update(float delta);

    virtual void render() const;

    virtual void draw() const;

    ~Scene();

    Entity& instantiate(Entity *entity);

    void removeEntity(Entity *entity);

    void destroy(Entity *entity);

    void setCamera(Camera &camera);

    void addLight(PointLight *light);

    void addLight(DirectionalLight *light);

    const std::vector<PointLight *> &getPointLights() const;

    const std::vector<DirectionalLight *> &getDirectionalLights() const;

    const Color &getAmbientLight() const;

    const Canvas &getCanvas() const;

    Input &getInput() const;

    Renderer &getRenderer() const;

    Camera &getCamera();

};

#pragma once

class Camera;

class Input;

class Entity;

class PointLight;

class DirectionalLight;

class Canvas;

class Renderer;

#include "Ressources/Color.h"
#include <set>

class Scene {
protected:
    Color ambient_light = Color(0.1f, 0.1f, 0.1f);
    std::set<Entity *> entities;


protected:
    Canvas *canvas;
    Input *input;
    Renderer *renderer;
    Camera *camera;
public:

    Scene() {};

    const std::set<Entity *> &getEntities() const;

    virtual void init(Canvas &canvas, Renderer &renderer, Input &input);

    virtual void update(float delta);

    virtual void render() const;

    virtual void draw() const;

    ~Scene();

    Entity &instantiate(Entity *entity);


    void destroy(Entity *entity);

    void setCamera(Camera &camera);

    const Color &getAmbientLight() const;

    const Canvas &getCanvas() const;

    Input &getInput() const;

    Renderer &getRenderer() const;

    Camera &getCamera() const;
    Camera*& getCameraPtr();
};

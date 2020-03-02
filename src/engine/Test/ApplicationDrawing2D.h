#pragma once

#include <Core/Scene.h>

#include <Core/Scene.h>

#include <Entities/Canvas/Point.h>
#include "map"

class ApplicationDrawing2D : public Scene {
private:
    class Tool {
    public:
        virtual void onMousePressed(double x, double y, ApplicationDrawing2D& scene) = 0;
        virtual void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) = 0;
    };

    class DrawPointTool : public Tool {
        bool pressed = false;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override {
            if(!pressed)
                scene.addEntity(new Point(glm::vec2(x, scene.getWindowHeight() - y), glm::vec2(2), scene.fill_color));

            pressed = true;
        };

        void onMouseReleased(double x, double y, ApplicationDrawing2D &scene) override {
            pressed = false;
        }
    };

    DrawPointTool drawPointTool = DrawPointTool();
    std::map<int, Tool*> tools = { {0, &drawPointTool} };
    unsigned int windowHeight;
    mutable Color background_color;
    mutable Color fill_color;
    mutable char line_width[4];
    mutable int tool = 0;

public:
    unsigned int getWindowHeight() const;

    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    void update(float delta) override;

    void draw() const override;

private:


};



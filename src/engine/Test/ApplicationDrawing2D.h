#pragma once

#include <Core/Scene.h>

#include <Core/Scene.h>

#include <Entities/Canvas/Ellipse.h>
#include <Entities/Canvas/Rect.h>
#include <Core/Log.h>
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
                scene.addEntity(new Ellipse(glm::vec2(x, scene.getWindowHeight() - y), glm::vec2(10), scene.fill_color));

            pressed = true;
        };

        void onMouseReleased(double x, double y, ApplicationDrawing2D &scene) override {
            pressed = false;
        }
    };

    class DrawEllipseTool : public Tool {
        Ellipse* ellipse = nullptr;
        glm::vec2 firstPoint = glm::vec2(0);
        bool pressed = false;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override {
            glm::vec2 point = glm::vec2(x, scene.getWindowHeight() - y);

            if(!pressed) {
                firstPoint = point;
                scene.addEntity(ellipse = new Ellipse(glm::vec2(point[0] , point[1]), glm::vec2(1), scene.fill_color));
            }
            else {
                ellipse->transform.position(glm::vec2(firstPoint[0] + (point[0] - firstPoint[0])/2, firstPoint[1] + (point[1] - firstPoint[1])/2));
                glm::vec2 size = glm::vec2(std::abs(point[0] - firstPoint[0]), std::abs(point[1] - firstPoint[1]));

                if(size[0] > 1 && size[1] > 1)
                    ellipse->transform.scale(glm::vec2(size[0], size[1]));
            }

            pressed = true;
        };

        void onMouseReleased(double x, double y, ApplicationDrawing2D &scene) override {
            pressed = false;
        }
    };

    class DrawRectangleTool : public Tool {
        Rect* rect = nullptr;
        glm::vec2 firstPoint = glm::vec2(0);
        bool pressed = false;

        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override{
            glm::vec2 point = glm::vec2(x, scene.getWindowHeight() - y);

            if(!pressed) {
                firstPoint = point;
                scene.addEntity(rect = new Rect(glm::vec2(point[0] , point[1]), glm::vec2(1), scene.fill_color));
            }
            else {
                glm::vec2 position = glm::vec2(firstPoint[0] + (point[0] - firstPoint[0])/2, firstPoint[1] + (point[1] - firstPoint[1])/2);
                rect->transform.position(position);
                glm::vec2 size = glm::vec2(std::abs(point[0] - firstPoint[0]), std::abs(point[1] - firstPoint[1]));

                if(size[0] > 1 && size[1] > 1)
                    rect->transform.scale(glm::vec2(size[0], size[1]));
            }

            pressed = true;
        }

        void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) override{
            pressed = false;
        }
    };

    DrawRectangleTool drawRectangleTool = DrawRectangleTool();
    DrawEllipseTool drawEllipseTool = DrawEllipseTool();
    DrawPointTool drawPointTool = DrawPointTool();
    std::map<int, Tool*> tools = { {0, &drawPointTool}, {2, &drawRectangleTool}, {4, &drawEllipseTool} };
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



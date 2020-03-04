#pragma once

#include <Core/Scene.h>

#include <Core/Scene.h>

#include <Entities/Canvas/Ellipse.h>
#include <Entities/Canvas/Rect.h>
#include <Core/Log.h>
#include <Entities/Canvas/Text.h>
#include <Shaders/Shader.h>
#include <Entities/Canvas/Image.h>
#include "map"
#include "Events/KeyPressListener.h"
#include "Entities/Spacial/MeshRenderer.h"
#include "Core/Rendering/Renderer.h"

class ApplicationDrawing2D : public Scene, KeyListener {
private:
    class Tool {
    public:
        virtual void onMousePressed(double x, double y, ApplicationDrawing2D& scene) = 0;
        virtual void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) = 0;
        virtual void onKeyPressed(int key, ApplicationDrawing2D& scene) = 0;
        virtual void onKeyReleased(int key, ApplicationDrawing2D& scene) = 0;
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

        void onKeyPressed(int key, ApplicationDrawing2D& scene) override {

        }

        void onKeyReleased(int key, ApplicationDrawing2D& scene) override {

        }
    };

    class DrawEllipseTool : public Tool {
        Ellipse* ellipse = nullptr;
        glm::vec2 firstPoint = glm::vec2(0);
        bool pressed = false;
        bool drawCircle = false;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override {
            glm::vec2 point = glm::vec2(x, scene.getWindowHeight() - y);

            if(!pressed) {
                firstPoint = point;
                scene.addEntity(ellipse = new Ellipse(glm::vec2(point[0] , point[1]), glm::vec2(1), scene.fill_color));
            }
            else {
                glm::vec2 size = glm::vec2(std::abs(point[0] - firstPoint[0]), std::abs(point[1] - firstPoint[1]));

                if(!(size[0] > 1 && size[1] > 1))
                    return;
                int signX = point[0] - firstPoint[0] > 0 ? 1: -1;
                int signY = point[1] - firstPoint[1] > 0 ? 1: -1;

                if(drawCircle) {
                    if(size[0] > size[1])
                        size[1] = size[0];
                    else
                        size[0] = size[1];
                }

                ellipse->transform.position(glm::vec2(firstPoint[0] + signX*size[0]/2, firstPoint[1] + signY*size[1]/2));
                ellipse->transform.scale(glm::vec2(size[0], size[1]));
            }

            pressed = true;
        };

        void onMouseReleased(double x, double y, ApplicationDrawing2D &scene) override {
            pressed = false;
        }

        void onKeyPressed(int key, ApplicationDrawing2D& scene) override {
            if(key == GLFW_KEY_LEFT_SHIFT)
                drawCircle = true;
        }

        void onKeyReleased(int key, ApplicationDrawing2D& scene) override {
            if(key == GLFW_KEY_LEFT_SHIFT)
                drawCircle = false;
        }
    };

    class DrawRectangleTool : public Tool {
        Rect* rect = nullptr;
        glm::vec2 firstPoint = glm::vec2(0);
        bool pressed = false;
        bool drawSquare = false;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override{
            glm::vec2 point = glm::vec2(x, scene.getWindowHeight() - y);

            if(!pressed) {
                firstPoint = point;
                scene.addEntity(rect = new Rect(glm::vec2(point[0] , point[1]), glm::vec2(1), scene.fill_color));
            }
            else {
                glm::vec2 size = glm::vec2(std::abs(point[0] - firstPoint[0]), std::abs(point[1] - firstPoint[1]));

                if(!(size[0] > 1 && size[1] > 1))
                    return;
                int signX = point[0] - firstPoint[0] > 0 ? 1: -1;
                int signY = point[1] - firstPoint[1] > 0 ? 1: -1;

                if(drawSquare) {
                    if(size[0] > size[1])
                        size[1] = size[0];
                    else
                        size[0] = size[1];
                }

                rect->transform.position(glm::vec2(firstPoint[0] + signX*size[0]/2, firstPoint[1] + signY*size[1]/2));
                rect->transform.scale(glm::vec2(size[0], size[1]));
            }

            pressed = true;
        }

        void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) override{
            pressed = false;
        }

        void onKeyPressed(int key, ApplicationDrawing2D& scene) override {
            if(key == GLFW_KEY_LEFT_SHIFT)
                drawSquare = true;
        }

        void onKeyReleased(int key, ApplicationDrawing2D& scene) override {
            if(key == GLFW_KEY_LEFT_SHIFT)
                drawSquare = false;
        }
    };

    class DrawTextTool : public Tool {
        bool pressed = false;
        Text* text;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override{
            if(!pressed) {
                scene.addEntity(text = new Text("", glm::vec2(x, scene.getWindowHeight() - y), *scene.font,100));
            }

            pressed = true;
        }

        void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) override{
            pressed = false;
        }

        void onKeyPressed(int key, ApplicationDrawing2D& scene) override {

        }

        void onKeyReleased(int key, ApplicationDrawing2D& scene) override {
            if(key == GLFW_KEY_BACKSPACE) {
                if(!text->getText().empty())
                    text->setText(text->getText().substr(0, text->getText().size() - 1));
            }
            else {
                text->setText(text->getText() + char(key));
            }
        }
    };

    class DrawImageTool : public Tool {
        bool pressed = false;
        Image* texture;
        void onMousePressed(double x, double y, ApplicationDrawing2D& scene) override{
            if(!pressed) {
                scene.addEntity(texture = new Image(glm::vec2(x, scene.getWindowHeight() - y), 0, glm::vec2(100,100), &scene.textureMat));
            }

            pressed = true;
        }

        void onMouseReleased(double x, double y, ApplicationDrawing2D& scene) override{
            pressed = false;
        }

        void onKeyPressed(int key, ApplicationDrawing2D& scene) override {

        }

        void onKeyReleased(int key, ApplicationDrawing2D& scene) override {

        }
    };
    DrawImageTool drawImageTool = DrawImageTool();
    DrawTextTool drawTextTool = DrawTextTool();
    DrawRectangleTool drawRectangleTool = DrawRectangleTool();
    DrawEllipseTool drawEllipseTool = DrawEllipseTool();
    DrawPointTool drawPointTool = DrawPointTool();
    std::map<int, Tool*> tools = { {0, &drawPointTool}, {1, &drawRectangleTool}, {2, &drawEllipseTool}, {3, &drawTextTool}, {4, &drawImageTool} };
    unsigned int windowHeight;
    mutable Color background_color;
    mutable Color fill_color;
    mutable char line_width[4];
    mutable int tool = 0;
    mutable char font_path[32] = "../res/consolas.bmp";
    mutable char font_width[32] = "128";
    mutable char font_height[32] = "128";
    mutable char texture_path[32] = "../res/consolas.bmp";
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/TextFragment.glsl");

    mutable FontMaterial* font = new FontMaterial(shader,"../res/consolas.bmp",128, 128);
    mutable Texture* texture = new Texture(texture_path);
    mutable CanvasMaterial textureMat = CanvasMaterial();
    mutable bool isHSV = false;
public:
    unsigned int getWindowHeight() const;

    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

    void update(float delta) override;

    void draw() const override;

    virtual ~ApplicationDrawing2D();

private:
    void onKeyPress(int key) override;

    void onKeyReleased(int key) override;

private:


};



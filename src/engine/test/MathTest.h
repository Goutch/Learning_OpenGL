//
// Created by User on 11-Dec.-2019.
//

#ifndef OGL_ENGINE_MATHTEST_H
#define OGL_ENGINE_MATHTEST_H


#include <core/Game.h>

class MathTest : public Game{
    Window* window;
    Renderer* renderer;
public:
    void init(Window &window, Renderer &renderer) override;

    void update() override;

    void render() override;
};


#endif //OGL_ENGINE_MATHTEST_H

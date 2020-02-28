#pragma once

#include <Core/Scene.h>
#include <unordered_map>
#include <vector>
#include <Shaders/Canvas/CanvasMaterial.h>
#include <Shaders/Shader.h>

class LSystem : public Scene {
    const std::string START = "F";
    const std::unordered_map<char, std::string> rules{
        {'F',"FF-[XY]+[XY]"},
        {'X',"+FY"},
            {'Y',"-FX"}

    };
    //pourcent to multiply line lenght each recursion
    const float LENGHT_REDUCTION=1;
    const float ANGLE_DEGREE=20;
    const vec3 START_POSITION=vec3(500,0,0);
    const unsigned int START_LENGHT=8;
    const unsigned int NUMBER_OF_RECURSE =5;
    std::vector<std::string> generations;

    Shader shader = Shader("../src/engine/Shaders/ShadersSources/LSystemVertex.glsl",
                                "../src/engine/Shaders/ShadersSources/LSystemFragment.glsl");
    CanvasMaterial material =CanvasMaterial(shader);
public:
    void init(const Canvas &canvas, Renderer &renderer, Input &input) override;

private:
    void generate();

    void turtle();

};


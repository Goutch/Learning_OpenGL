#pragma once

#include <Core/Scene.h>
#include <unordered_map>
#include <vector>

class LSystem : public Scene {
    const std::string START = "X";
    const std::unordered_map<char, std::string> rules{
        {'X',"F+[[X]-X]-F[-FX]+X"},
            {'F',"FF"}
    };
    //pourcent to multiply line lenght each recursion
    const float LENGHT_REDUCTION=1;
    const float ANGLE_DEGREE=25;
    const vec3 START_POSITION=vec3(300,300,0);
    const unsigned int START_LENGHT=10;
    const unsigned int NUMBER_OF_RECURSE = 6;
    std::vector<std::string> generations;
    std::vector<std::tuple<vec3, vec3>> lines;

public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

private:
    void generate();

    void turtle();

public:
    void draw() const override;
};


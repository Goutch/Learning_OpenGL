//
// Created by User on 04-Feb.-2020.
//
#include <Core/Canvas.h>
#include <Core/Log.h>
#include "LSystem.h"
#include <Core/Rendering/Renderer.h>
#include <stack>

void LSystem::init(const Canvas &canvas, Renderer &renderer, Input &input) {
    Scene::init(canvas, renderer, input);
    generations.push_back(START);
    for (int i = 0; i < NUMBER_OF_RECURSE; ++i) {
        generate();
    }
    turtle();
}

void LSystem::generate() {
    std::string &last_gen = generations.back();
    std::string current_gen = "";
    for (int i = 0; i < last_gen.size(); ++i) {
        char k = last_gen.at(i);
        if (rules.find(k) != rules.end()) {
            current_gen += rules.at(k);
        } else {
            current_gen += k;
        }
    }
    generations.push_back(current_gen);
}

#include <Entities/Canvas/Line.h>

void LSystem::turtle() {
    float rot = glm::radians(ANGLE_DEGREE);
    std::stack<CanvasTransform> saves;
    CanvasTransform t;
    t.translate(START_POSITION);
    unsigned int len = START_LENGHT;
    for (int j = 0; j <generations.size() ; ++j) {
        std::string path = generations[j];
        len *= LENGHT_REDUCTION;
        for (int i = 0; i < path.size(); ++i) {

            char current = path.at(i);
            switch (current) {
                case 'F': {
                    vec2 begin = t.position();
                    t.translate(vec3(0, len, 0));
                    addEntity(new Line(begin,t.position(),2,material));
                }
                    break;
                case '+':
                    t.rotate(-rot);
                    break;
                case '-':
                    t.rotate(rot);
                    break;
                case '[':
                    saves.push(CanvasTransform(t));
                    break;
                case ']':
                    t=saves.top();
                    saves.pop();
                    break;
                default:
                    break;
            }
        }
    }

}

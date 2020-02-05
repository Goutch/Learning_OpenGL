//
// Created by User on 04-Feb.-2020.
//
#include <Core/Viewport.h>
#include <Core/Log.h>
#include "LSystem.h"
#include <Core/Rendering/Renderer.h>
#include <stack>

void LSystem::init(Viewport &viewport, Renderer &renderer, Window &window) {
    Scene::init(viewport, renderer, window);
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

void LSystem::draw() const {
    Scene::draw();
    for (int i = 0; i < lines.size(); ++i) {
        vec3 p1=std::get<0>(lines[i]);
        vec3 p2=std::get<1>(lines[i]);
        renderer->drawLine(p1.x,p1.y,p2.x,p2.y,1,Color::WHITE);
    }
}


void LSystem::turtle() {


    float rot = glm::radians(ANGLE_DEGREE);

    std::stack<Transform> saves;
    Transform t;

    t.translate(START_POSITION);
    unsigned int len = START_LENGHT;
    for (int j = 0; j <generations.size() ; ++j) {
        std::string path = generations[j];
        len *= LENGHT_REDUCTION;
        for (int i = 0; i < path.size(); ++i) {

            char current = path.at(i);
            switch (current) {
                case 'F': {
                    vec3 begin = t.position();
                    t.translate(vec3(0, len, 0));
                    lines.emplace_back(begin,t.position());
                }
                    break;
                case '+':
                    t.rotate(vec3(0, 0, -rot));
                    break;
                case '-':
                    t.rotate(vec3(0, 0, rot));
                    break;
                case '[':
                    saves.push(t);
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

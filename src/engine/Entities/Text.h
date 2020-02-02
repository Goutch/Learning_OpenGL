//
// Created by le6mon on 2020-02-02.
//

#ifndef OGL_ENGINE_TEXT_H
#define OGL_ENGINE_TEXT_H


#include <Shaders/FontMaterial.h>
#include "Entity.h"

class Text : public Entity {
private:
    FontMaterial& font;
    Mesh mesh = Mesh();
public:
    Text(std::string text, const vec3 &position, FontMaterial &font);

public:
    void init(Scene &scene) override;

    void render(const Scene &scene) const override;

    void update(float delta, Scene &scene) override;

    void destroy(Scene &scene) override;
};


#endif //OGL_ENGINE_TEXT_H

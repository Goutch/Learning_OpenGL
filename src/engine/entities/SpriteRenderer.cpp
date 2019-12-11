//
// Created by User on 22-Nov.-2019.
//

#include "SpriteRenderer.h"
#include "core/Renderer.h"
#include "graphics/shaders/EntityShader.h"
#include "graphics/Sprite.h"
SpriteRenderer::SpriteRenderer(Sprite* sprite, EntityShader* shader, glm::vec3 pos):Entity(pos) {
    this->sprite=sprite;
    this->shader=shader;
}

void SpriteRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(this);
}

void SpriteRenderer::update(float delta, Window &window) {

}

EntityShader &SpriteRenderer::getShader() {
    return *shader;
}

Drawable &SpriteRenderer::getDrawable() {
    return *sprite;
}

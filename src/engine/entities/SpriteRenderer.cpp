//
// Created by User on 22-Nov.-2019.
//

#include "SpriteRenderer.h"
#include "core/Renderer.h"
#include "graphics/shaders/BaseShader.h"
#include "graphics/Sprite.h"
SpriteRenderer::SpriteRenderer(Sprite* sprite, BaseShader* shader, glm::vec3 pos) {
    this->sprite=sprite;
    this->shader=shader;
    transform.translate(pos);
}

void SpriteRenderer::render(Renderer &renderer) {
    renderer.addToRenderQueue(this);
}

void SpriteRenderer::update(float delta, Window &window) {

}

BaseShader &SpriteRenderer::getShader() {
    return *shader;
}

Drawable &SpriteRenderer::getDrawable() {
    return *sprite;
}

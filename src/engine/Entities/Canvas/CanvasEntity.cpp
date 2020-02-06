//
// Created by User on 05-Feb.-2020.
//

#include "CanvasEntity.h"
void CanvasEntity::init(Scene &scene) {}
void CanvasEntity::update(float delta, Scene &scene) {}
void CanvasEntity::draw(const Scene &scene) const{}
void CanvasEntity::onDestroy(Scene &scene) {}

CanvasEntity::CanvasEntity() {

}
CanvasEntity::CanvasEntity(vec2 position, float rotation, vec2 scale) {
    transform.translate(position);
    transform.rotate(rotation);
    transform.scale(scale);
}

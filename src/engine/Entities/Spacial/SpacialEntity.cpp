//
// Created by User on 2020-01-06.
//

#include "SpacialEntity.h"
SpacialEntity::SpacialEntity(vec3 position, vec3 rotation, vec3 scale) {
    transform.translate(position);
    transform.rotate(quat(rotation));
    transform.scale(scale);
}
void SpacialEntity::onDestroy(SpacialScene &scene) {}
void SpacialEntity::draw(const SpacialScene &scene) const{}
void SpacialEntity::update(float delta, SpacialScene &scene) {}
void SpacialEntity::init(SpacialScene &scene) {}


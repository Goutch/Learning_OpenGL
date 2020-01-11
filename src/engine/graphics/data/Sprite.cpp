
#include "Sprite.h"
#include "Texture.h"
#include "graphics/Geometry.h"
Sprite::Sprite():VAO() {
    Geometry::makeQuad(*this);
}
Sprite::Sprite(Texture& texture):VAO(){
    Geometry::makeQuad(*this);
    setTexture(texture);
}
void Sprite::bind() const {
    VAO::bind();
    texture->bind();
}

void Sprite::setTexture(Texture &texture) {
    this->texture=&texture;
}



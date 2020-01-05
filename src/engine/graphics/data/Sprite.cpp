
#include "Sprite.h"
#include "Texture.h"
Sprite::Sprite(Texture& texture):VAO(){
    float vert[8]={-0.5f,-0.5f,
                   -0.5f,0.5,
                   0.5f,0.5f,
                   0.5f,-0.5f};
    float uvs[8]={0,0,
                  0,1,
                  1,1,
                  1,0};
    unsigned int indices[6]={0,1,2,2,3,0};
    indicies(indices,6);

    put(0,2,vert,8);
    put(2,2,uvs,8);
    setTexture(texture);
}
void Sprite::bind() {
    bind();
    texture->bind();
}

void Sprite::setTexture(Texture &texture) {
    this->texture=&texture;

}